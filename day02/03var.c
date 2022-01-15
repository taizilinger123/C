/*
   变量练习
*/
#include <stdio.h>
int main(){
  int  num = 3, num1 = 7;
  printf("num是%d,num1是%d\n", num, num1);
 /* int num2 = 0;
  num2 = num;
  num = num1;
  num1 = num2;*/
/*num = num + num1;
  num1 = num - num1;
  num = num - num1;*/
  num = num - num1;
  num1 = num + num1;
  num = num1 - num;
  printf("num是%d,num1是%d\n", num, num1);
  return 0;
}
