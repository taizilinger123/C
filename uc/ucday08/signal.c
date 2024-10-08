#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void fa(int signo){//信号值
   printf("捕获了信号%d\n",signo);
}

int main(){
   printf("pid=%d\n",getpid());
   signal(SIGINT,fa);//改变了2退出信号(ctrl+c) SIGINT(Signal Interrupt)的处理方式
   //由原先的默认处理  变成了  调用fa函数处理,
   //到这里会一直执行下去,直到最后的while(1)函数我们给signal函数
   //发送ctrl+c退出信号才会执行fa这个函数
   if(signal(SIGQUIT,SIG_IGN)==SIG_ERR)//忽略
	   perror("signal"),exit(-1);
   signal(9,fa);//无效，9不能改变处理方式
   while(1);
}



/*
 root@test:/home/test/biaoc/C/uc/ucday08# a.out
 pid=2369        kill -9 2369
 ^C捕获了信号2   ctrl+c  取消不了
 ^\              ctrl+\  取消不了
root@test:/home/test/biaoc/C/uc/ucday08# kill  -2  2613 
root@test:/home/test/biaoc/C/uc/ucday08# kill  -3  2613 
root@test:/home/test/biaoc/C/uc/ucday08# kill  -9  2613 
root@test:/home/test/biaoc/C/uc/ucday08# kill  -11  2616
root@test:/home/test/biaoc/C/uc/ucday08# kill  -7  2618

root@test:/home/test/biaoc/C/uc/ucday08# a.out
pid=2613
捕获了信号2
已杀死
root@test:/home/test/biaoc/C/uc/ucday08# a.out
pid=2614
段错误 (核心已转储)
root@test:/home/test/biaoc/C/uc/ucday08# a.out
pid=2616
段错误 (核心已转储)
root@test:/home/test/biaoc/C/uc/ucday08# a.out
pid=2618
总线错误 (核心已转储)
kill  -l 可以查看所有的信号
 */
