/*
 十进制转二进制练习
 */
#include <stdio.h>
int main(){
   int num = 0;
   int bit0 = 0, bit1 = 0, bit2 = 0, bit3 = 0, 
	   bit4 = 0, bit5 = 0, bit6 = 0, bit7 = 0;
   printf("请输入一个数字：");
   scanf("%d", &num);
   bit0 = num % 2;
   num = num / 2;
   bit1 = num % 2;
   num = num / 2;
   bit2 = num % 2;
   num = num / 2;
   bit3 = num % 2;
   num = num / 2;
   bit4 = num % 2;
   num = num / 2;
   bit5 = num % 2;
   num = num / 2;
   bit6 = num % 2;
   num = num / 2;
   bit7 = num % 2;
   num = num / 2;
   printf("%d%d%d%d %d%d%d%d\n", bit7, bit6, bit5, bit4, bit3, bit2, bit1, bit0);
   return 0;
}

