#include <stdio.h>
#include "qa.h"

int main(){
   QUEUE queue;
   queue_init(&queue,4);
   int i;
   for(i=1;i<5;i++){
      if(!queue_full(&queue))
		  queue_push(&queue,i);
   }
   printf("%d\n",queue_pop(&queue));
   printf("%d\n",queue_pop(&queue));
   queue_push(&queue,50);
   queue_push(&queue,60);
   while(!queue_empty(&queue))
	   printf("%d\n",queue_pop(&queue));
   queue_deinit(&queue);
   return 0;
}

/*
 root@test:/home/test/biaoc/C/day19# gcc  testqa.c  qa.c
 root@test:/home/test/biaoc/C/day19# ./a.out 
 1
 2
 3
 4
 */
