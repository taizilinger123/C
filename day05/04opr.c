/*
 操作符练习
 */
#include <stdio.h>
int main(){
   int num = 0, num1 = 0;
   printf("计算结果是%d\n", (1+2, 3+4));
   num = 3, 8;
   printf("num是%d\n", num);
   num1 = num = 5;
   printf("num是%d, num1是%d\n", num, num1);
   num *= 3 + 4;
   printf("num是%d\n", num);
   return 0;
}
