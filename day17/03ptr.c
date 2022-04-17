/*
 指针计算练习
 */
#include <stdio.h>
int main(){
   int num[] = {1, 2, 3};
   int *p_num = num;
   int *p_num1 = num + 3;
   char *p_ch = (char *)num;
   printf("p_num是%p\n", p_num);
   printf("p_num + 1是%p\n", p_num + 1);
   printf("p_num - 1是%p\n", p_num - 1);
   printf("p_ch是%p\n", p_ch);
   printf("p_ch + 1是%p\n", p_ch + 1);
   printf("p_ch - 1是%p\n", p_ch - 1);
   p_num++;
   printf("p_num是%p\n", p_num);
   printf("p_num1 - p_num是%d\n", p_num1 - p_num);
   return 0;
}
