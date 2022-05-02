#include <stdio.h>
#include "sa.h"

int main(){
   STACK stack;//stack的内存ok,但arr内存没有
   stack_init(&stack,10);//内存完全搞定
   int i=1;
   while(!stack_full(&stack)){
      stack_push(&stack,i++);
   }
   while(!stack_empty(&stack)){
      printf("%d\n",stack_pop(&stack));
   }
   stack_deinit(&stack);//内存被释放
}

//gcc  sa.c  testsa.c
/*
 root@test:/home/test/biaoc/C/day18# ./a.out
 10
 9
 8
 7
 6
 5
 4
 3
 2
 1
 */
