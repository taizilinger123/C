#include <stdio.h>
#include "bt.h"

int main(){
   BSTREE bstree;
   bstree_init(&bstree);
   bstree_insert(&bstree,5);
   bstree_insert(&bstree,7);
   bstree_insert(&bstree,2);
   bstree_insert(&bstree,6);
   bstree_insert(&bstree,4);
   bstree_insert(&bstree,3);
   bstree_insert(&bstree,1);
   bstree_insert(&bstree,9);
   bstree_insert(&bstree,8);
   bstree_travel(&bstree);
   printf("size=%d\n",bstree_size(&bstree));
   bstree_erase(&bstree,2);//删除
   bstree_travel(&bstree);
   bstree_update(&bstree,5,10);
   bstree_travel(&bstree);
   bstree_deinit(&bstree);
}


/*
 gcc  -c  bt.c
 gcc  testbt.c bt.c
 ./a.out
 root@test:/home/test/biaoc/C/day21# ./a.out 
 1 2 3 4 5 6 7 8 9 
 size=9
 1 3 4 5 6 7 8 9 
 1 3 4 6 7 8 9 10
 */
