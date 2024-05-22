#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

void fa(int signo){
  printf("i am superman\n");
}
int main(){
  signal(SIGALRM,fa);
  struct itimerval timer;
  //间隔时间1.1秒
  timer.it_interval.tv_sec=1;//间隔秒数
  timer.it_interval.tv_usec = 100000;//微秒数
  //开始时间3秒(第一次)
  timer.it_value.tv_sec=3;//开始秒数
  timer.it_value.tv_usec = 0;//微秒数
  setitimer(ITIMER_REAL,&timer,0);
  while(1);
}
