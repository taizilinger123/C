/*
 指针练习
 */
#include <stdio.h>
int main(){
   int num = 0, num1 = 0, num2 = 0;
   int *p_num = NULL, *p_num1 = NULL, *p_num2 = NULL;
   p_num = &num;
   p_num1 = &num1;
   p_num2 = &num2;
   printf("请输入三个数字：");
   scanf("%d %d %d", p_num, p_num1, p_num2);
   if (*p_num < *p_num1){
       *p_num += *p_num1;
	   *p_num1 = *p_num - *p_num1;
	   *p_num = *p_num - *p_num1;
   }
   if (*p_num < *p_num2) {
       *p_num += *p_num2;
	   *p_num2 = *p_num - *p_num2;
	   *p_num = *p_num - *p_num2;
   }
   printf("最大数是%d\n", *p_num);
   return 0;
}
