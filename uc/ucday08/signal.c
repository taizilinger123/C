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
