/*
  scanf练习
 */
#include <stdio.h>
int main(){
   int num = 0, num1 = 0;
   printf("请输入两个数字：");
   scanf("%d %d", &num, &num1);
   printf("%d %d\n", num, num1);
   return 0;
}
