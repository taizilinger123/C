/*
 标准函数练习
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
   int num = atoi("123");
   double d_num = atof("2.78");
   printf("num是%d\n", num);
   printf("d_num是%lg\n", d_num);
   num = sqrt(36);
   printf("36的平方根是%d\n", num);
   num = pow(2, 3);
   printf("2的3次方是%d\n", num);
   return 0;
}


//gcc  -lm  10func.c
//./a.out
