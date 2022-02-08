/*
 最大数练习
 */
#include <stdio.h>
int main(){
   int num1 = 0, num2 = 0, num3 = 0, num = 1 << 31;
   printf("请输入三个数字：");
   scanf("%d %d %d", &num1, &num2, &num3);
   if (num1 > num) {
      num = num1;
   }   
   if (num2 > num) {
     num = num2;
   }
   if (num3 > num) {
     num = num3;
   }
   printf("最大数是%d\n", num);
   return 0;
}
