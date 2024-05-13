#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void fa(int signo){//信号值
   printf("捕获了信号%d\n",signo);
}

int main(){
   printf("pid=%d\n",getpid());
   signal(SIGINT,fa);
   if(signal(SIGQUIT,SIG_IGN)==SIG_ERR)
	   perror("signal"),exit(-1);
   //signal(9,fa);
   while(1);
}



/*
 root@test:/home/test/biaoc/C/uc/ucday08# a.out
 pid=2369        kill -9 2369
 ^C捕获了信号2   ctrl+c  取消不了
 ^C捕获了信号2
 ^C捕获了信号2
 ^C捕获了信号2
 ^\              ctrl+\  取消不了
 ^C捕获了信号2
 ^C捕获了信号2
 ^C捕获了信号2
 ^C捕获了信号2
 ^\^\^\^\已杀死

 */
