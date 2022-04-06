/*
 多文件程序编写练习
 */
#include <stdio.h>
#include "14add1.h"   //双引号是从当前位置进行查找
extern int result;    //这个result变量是有的，当运行的时候去另一个文件里找这个全局变量
int main(){
   add(2,  4);
   printf("add(2, 4)是%d\n", result);
   return 0;
}



/*
 root@test:/home/test/biaoc/C/day14# gcc 14add.c  14add1.c
 root@test:/home/test/biaoc/C/day14# ./a.out 
 add(2, 4)是6
 )
 */
