/*
 生命周期演示
 */
#include <stdio.h>
void f(){
  static int num = 7;
  printf("num是%d\n", num);
  num = 3;
}
void f1(){
  int num = 7;
  int num1 = 8;
  int num2 = num + num1;
}
int main(){
  f();
  f1();
  f();
  return 0;
}
