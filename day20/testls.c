#include <stdio.h>
#include "ls.h"

int main(){
   LIST list;
   list_init(&list);
   list_append(&list,10);
   list_append(&list,30);
   list_append(&list,50);
   list_insert(&list,1,20);
   list_insert(&list,3,40);
   for(list_begin(&list);!list_end(&list);list_next(&list)){
       printf("%d ",*list_current(&list));
   }   
   printf("\n");
   list_append(&list,40);list_append(&list,40);
   list_erase(&list,1);//删除20
   list_remove(&list,40);
   list_begin(&list);
   while(!list_end(&list)){
       printf("%d ",*list_next(&list));
   }
   printf("\n");
   list_deinit(&list);
}

/*
 root@test:/home/test/biaoc/C/day20# gcc  testls.c  ls.c
 root@test:/home/test/biaoc/C/day20# ./a.out 
 10 20 30 40 50 
 10 30 50 
 */
