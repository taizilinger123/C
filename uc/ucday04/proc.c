#include <stdio.h>

int main(){
   int x = 10;
   printf("x=%d,&x=%p\n",x,&x);
   while(1);
}

/*
 root@test:/home/test/biaoc/C/uc/ucday04# gcc  proc.c -oa
 root@test:/home/test/biaoc/C/uc/ucday04# a
 x=10,&x=0x7ffcbe8e2a64

 */
