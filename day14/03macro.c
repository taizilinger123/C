/*
 宏练习
 */
#include <stdio.h>
#define  SIZE  6
int main(){
   int num[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
   int pos = 0;
   for(pos = 0;pos <= SIZE - 1;pos++){
      printf("%d", num[pos]);
   }
   printf("\n");
   return 0;
}


//gcc  -DSIZE=6  03macro.c 在编译的时候确定数字用宏，可以省略上面的define，在编写的时候确定用变量
