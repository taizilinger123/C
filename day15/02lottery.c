/*
 彩票练习
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "02lottery1.h"
extern  int lottery[];
int main(){
   int pos = 0;
   srand(time(0));
   create_lottery();
   for(pos = 0;pos<=6;pos++){
      printf("%d ", lottery[pos]);
   }
   printf("\n");
   return 0;
}


//:7,13w  02lottery1.c
//gcc  02lottery.c 02lottery1.c
//root@test:/home/test/biaoc/C/day15# ./a.out 
//12 23 11 10 3 35 2 
