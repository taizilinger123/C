/*
 指针变量做返回值练习
 */
#include <stdio.h>
int *f(){
   int num = 4;
   return &num;
}
void f1(){
  int num = 7;
  int num1 = 8;
  int num2 = num + num1;
}
int main(){
  int *p_num = f();
  *p_num = 10;
  f1();
  printf("*p_num是%d\n", *p_num);
  return 0;
}
