/*
 指针变量做返回值练习
 */
#include <stdio.h>
//获得最大数
int max(int num, int num1){
   return num > num1 ? num : num1;
}
//获得最大变量
int *max1(int *p_num, int *p_num1){
  return *p_num > *p_num1 ? p_num : p_num1;
}
int main(){
   int num = 3, num1 = 7;
   int *p_num = max1(&num, &num1);
   *p_num = 10;
   printf("num是%d,num1是%d\n", num, num1);
   return 0;
}
