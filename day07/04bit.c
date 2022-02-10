/*
 二进制打印练习
 */
#include <stdio.h>
int main(){
   int num = 0;
   unsigned int num1 = 1 << 7;
   char ch = 0;
   printf("请输入一个字符：");
   scanf("%c", &ch);
   printf("ch是0x%hhx\n", ch);
   for(num = 7;num >= 0;num --){
      printf("%d", (ch & num1) >> num);
	  num1 >>= 1;
   }
   printf("\n");
   return 0;
}
