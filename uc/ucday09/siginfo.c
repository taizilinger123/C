#include <stdio.h>
#include <signal.h>

void fa(int signo,siginfo_t* info,void* p){
  printf("进程%d发来信号%d\n",info->si_pid,signo);
}
int main(){
  struct sigaction action = {};
  //SA_SIGINFO和成员sa_sigaction函数指针是一对
  action.sa_flags = SA_SIGINFO;
  action.sa_sigaction = fa;
  sigaction(SIGINT,&action,NULL);
  printf("PID=%d\n",getpid());
  while(1);
}

/*
 root@test:/home/test/biaoc/C/uc/ucday09# a.out
 PID=13679
 ^C进程0发来信号2
 ^C进程0发来信号2
 ^C进程0发来信号2
 进程11894发来信号2
 ^\退出 (核心已转储) //ctrl+\
 //新开终端，执行以下代码
 root@test:/home/test/biaoc/C/uc/ucday09# kill -2 13679
 root@test:/home/test/biaoc/C/uc/ucday09# ps
   PID TTY          TIME CMD
   11892 pts/9    00:00:00 sudo
   11893 pts/9    00:00:00 su
   11894 pts/9    00:00:00 bash    ####可以看到11894的bash
   13680 pts/9    00:00:00 ps
 */
