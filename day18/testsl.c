#include <stdio.h>
#include "sl.h"

int main(){
   STACK stack;
   stack_init(&stack);
   int i=0;
   for(;i<10;i++){
      stack_push(&stack,i);
   }
   printf("size=%d\n",stack_size(&stack));
   while(!stack_empty(&stack))
	   printf("%d\n",stack_pop(&stack));
   stack_deinit(&stack);
}


//gcc   testsl.c  sl.c
/*
 root@test:/home/test/biaoc/C/day18# ./a.out 
 size=10
 9
 8
 7
 6
 5
 4
 3
 2
 1
 0
 */
