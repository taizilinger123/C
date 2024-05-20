#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void fa(int signo){
    printf("捕获了信号%d\n",signo);
}
int main(){
    signal(SIGINT,fa);signal(SIGQUIT,fa);//2,3不可靠信号(不支持排队),会丢失
	signal(50,fa);//可靠信号(支持排队,排队是针对相同信号来说的)，不会丢失
	printf("pid=%d\n",getpid());
	printf("执行普通代码，没有屏蔽信号\n");
	sleep(20);//会被第一个发来的信号中断
	printf("模拟关键代码，开始信号屏蔽\n");
	sigset_t set,old;//set屏蔽信号  old存之前的
	sigemptyset(&set); sigaddset(&set,SIGINT);
	sigaddset(&set,SIGQUIT); sigaddset(&set,50);
	sigprocmask(SIG_SETMASK,&set,&old);
	sleep(15);
	sigset_t pend;//获取来过的被屏蔽的信号
	sigpending(&pend);
	if(sigismember(&pend,SIGINT)){
	  printf("信号SIGINT来过\n");
	}
	if(sigismember(&pend,SIGQUIT)){
	  printf("信号SIGQUIT来过\n");
	}
	printf("关键代码执行完毕，解除信号屏蔽\n");
	sigprocmask(SIG_SETMASK,&old,0);
}

/*
 root@test:/home/test/biaoc/C/uc/ucday09# gcc  sigmask.c 
 root@test:/home/test/biaoc/C/uc/ucday09# a.out
 pid=11934
 执行普通代码，没有屏蔽信号
 捕获了信号3
 模拟关键代码，开始信号屏蔽
 关键代码执行完毕，解除信号屏蔽
 捕获了信号50
 捕获了信号3
 捕获了信号2
 root@test:/home/test/biaoc/C/uc/ucday09# kill -3 11934 //模拟发信号3
 root@test:/home/test/biaoc/C/uc/ucday09# kill -3 11934
 root@test:/home/test/biaoc/C/uc/ucday09# kill -2 11934 //模拟发信号2
 root@test:/home/test/biaoc/C/uc/ucday09# kill -2 11934
 root@test:/home/test/biaoc/C/uc/ucday09# kill -50 11934 //模拟发信号50
###################################################################
root@test:/home/test/biaoc/C/uc/ucday09# gcc sigmask.c 
t@test:/home/test/biaoc/C/uc/ucday09# a.out 
pid=12208
执行普通代码，没有屏蔽信号
捕获了信号2
模拟关键代码，开始信号屏蔽
信号SIGINT来过
关键代码执行完毕，解除信号屏蔽
捕获了信号2
root@test:/home/test/biaoc/C/uc/ucday09# kill -2 12208
root@test:/home/test/biaoc/C/uc/ucday09# kill -2 12208
root@test:/home/test/biaoc/C/uc/ucday09# kill -2 12208
root@test:/home/test/biaoc/C/uc/ucday09# kill -2 12208
root@test:/home/test/biaoc/C/uc/ucday09# kill -2 12208
 */
