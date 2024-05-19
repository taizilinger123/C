#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void fa(int signo){
  printf("时间到，信号%d喊你偷菜\n",signo);
  alarm(1);
}

int main(){
  signal(SIGALRM,fa);
  alarm(5);//5秒后产生SIGALRM信号
  sleep(2);
  int res = alarm(5);//res = 3
  printf("res=%d\n",res);
  sleep(1);
  //alarm(0);//取消闹钟
  while(1);
}

/*
 root@test:/home/test/biaoc/C/uc/ucday09# gcc alarm.c
 root@test:/home/test/biaoc/C/uc/ucday09# a.out
 res=3
 时间到，信号14喊你偷菜
 时间到，信号14喊你偷菜
 时间到，信号14喊你偷菜
 时间到，信号14喊你偷菜
 时间到，信号14喊你偷菜
 */
