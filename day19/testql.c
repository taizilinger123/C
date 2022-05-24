#include <stdio.h>
#include "ql.h"

int main(){
  QUEUE queue;
  queue_init(&queue);
  int i;
  for(i=1;i<11;i++){
      queue_push(&queue,i);
  }
  while(!queue_empty(&queue))
     printf("%d\n",queue_pop(&queue));
  queue_deinit(&queue);
  return 0;
}


/*
 root@test:/home/test/biaoc/C/day19# gcc testql.c ql.c
 root@test:/home/test/biaoc/C/day19# ./a.out 
 1
 2
 3
 4
 5
 6
 7
 8
 9
 10 
 */
