#include <stdio.h>
#include <signal.h>

int main(){
  printf("size=%d\n",sizeof(sigset_t));
  sigset_t set;
  sigemptyset(&set);
  printf("set=%d\n",set);//0
  sigaddset(&set,2);//2的一次方
  printf("set=%d\n",set);//2
  sigaddset(&set,3);//2的2次方     
  printf("set=%d\n",set);//2+4 (110) 6
  sigaddset(&set,7);//2的3次方
  printf("set=%d\n",set);//2+4+64 = 70
  sigdelset(&set,3);//去掉2的2次方
  printf("set=%d\n",set);//70-4 = 66
  if(sigismember(&set,2)){
    printf("包括信号2\n");
  }
}
