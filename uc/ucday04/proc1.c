#include <stdio.h>

int main(){
  int* p = (int*)0x7ffcbe8e2a64;
  printf("*p=%d\n",*p);
}

/*
 root@test:/home/test/biaoc/C/uc/ucday04# gcc proc1.c -ob
 root@test:/home/test/biaoc/C/uc/ucday04# b
 段错误 (核心已转储)
 */
