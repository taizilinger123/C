/*
 条件编译练习
 */
#include <stdio.h>
int main(){
//定义WINDOWS宏,如果是windows宏就编译第8行，否则编译第10行
#ifndef WINDOWS
   printf("1\n");
#else
   printf("2\n");
#endif  //WINDOWS
   return 0;
}

/*
 root@test:/home/test/biaoc/C/day14# gcc  -DWINDOWS  11compile.c 
 root@test:/home/test/biaoc/C/day14# ./a.out
 1
 root@test:/home/test/biaoc/C/day14# 
 root@test:/home/test/biaoc/C/day14# gcc  11compile.c 
 root@test:/home/test/biaoc/C/day14# ./a.out 
 2
 */
