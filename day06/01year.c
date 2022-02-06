/*
 润年练习
 */
#include <stdio.h>
#include <stdbool.h>
int main(){
   int year = 0;
   bool bl = false;
   printf("请输入年份数字：");
   scanf("%d", &year);
   (!(year % 400))||((!(year % 4))&&(year % 100));
   printf("bl是%d\n", bl);
   return 0;
}
