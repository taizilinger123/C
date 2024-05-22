#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void fa(int signo,siginfo_t* info,void* p){
   printf("进程%d发来了信号%d,附带了值%d\n",
	 info->si_pid,signo,info->si_value);
}
int main(){
   struct sigaction action = {};
   action.sa_flags = SA_SIGINFO;
   action.sa_sigaction = fa;
   sigaction(50/*SIGINT*/,&action,NULL);//SIGINT是信号2非可靠信号所以会丢失和阻塞
   pid_t pid = fork();
   if(pid==0){
     int i;
	 for(i=0;i<100;i++){
	   union sigval v; v.sival_int = i;
	   sigqueue(getppid(),50/*SIGINT*/,v);
	 }
	 exit(0);
   }
   while(1);
}
