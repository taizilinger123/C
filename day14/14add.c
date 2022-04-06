/*
 多文件程序编写练习
 */
#include <stdio.h>
#include "14add1.h"   //双引号是从当前位置进行查找
int main(){
   printf("add(2, 4)是%d\n", add(2, 4));
   return 0;
}



/*
 root@test:/home/test/biaoc/C/day14# gcc 14add.c  14add1.c
 root@test:/home/test/biaoc/C/day14# ./a.out 
 add(2, 4)是6
 )
 */
