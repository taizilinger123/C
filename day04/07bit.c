/*
   八进制和十六进制练习
   */
#include <stdio.h>
int main(){
   int num = 011;
   printf("num是%d\n", num);
   printf("num是0%o\n", num);
   num = 0x1d;
   printf("num是%d\n", num);
   printf("num是0x%x\n",  num);
   printf("num是0X%X\n", num);
   return 0;
}
