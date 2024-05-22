#include <stdio.h>
#include <signal.h>

void fa(int signo){
  printf("捕获了信号%d\n",signo);
  sleep(5);
}//在信号处理函数执行期间，信号自身和sa_mask中的信号会被屏蔽
int main(){
  struct sigaction action = {};
  action.sa_handler = fa;//指定信号处理函数
  sigemptyset(&action.sa_mask);
  sigaddset(&action.sa_mask,SIGQUIT);
  //action.sa_flags = SA_RESETHAND;//只执行一次处理函数后恢复默认
  action.sa_flags = SA_NOMASK;//在信号处理函数执行期间，解除对信号自身的屏蔽
  sigaction(SIGINT,&action,NULL);
  while(1);
}

/*
 root@test:/home/test/biaoc/C/uc/ucday09# gcc sigaction.c 
 sigaction.c: In function ‘fa’:
sigaction.c:6:3: warning: implicit declaration of function ‘sleep’ [-Wimplicit-function-declaration]
sleep(5);
^
root@test:/home/test/biaoc/C/uc/ucday09# a.out
^C捕获了信号2   //ctrl+c
^C^C^C^C^C^C^C^C^C^C^C^\捕获了信号2
^\^\^\^\^\^\^\^\^\^\^\^\^\^\^\^\^\^\^\^\^\^\^\^\^\^\退出 (核心已转储)  //ctrl+\
 */
