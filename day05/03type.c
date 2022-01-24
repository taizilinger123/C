/*
   整数类型间赋值练习
 */
#include <stdio.h>
int main(){
   char ch = 128;
   unsigned char uch = 255;
   int num = 0;
   printf("ch是%hhd\n", ch);
   ch = 191;
   printf("ch是%hhd\n", ch);
   ch = -1;
   num = ch;
   printf("num是%d\n", num);
   num = uch;
   printf("num是%d\n", num);
   return 0;
}
