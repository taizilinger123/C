/*
   自增，自减操作符练习
 */
#include <stdio.h>
int num2 = 5;
int main(){
  int num = 0, num1 = 0;
  num++;
  printf("num是%d\n", num);
  num--;
  printf("num是%d\n", num);
  //3++;  只能对变量进行操作
  ++num;
  printf("num是%d\n", num);
  --num;
  printf("num是%d\n", num);
  num1 = num++;
  printf("num是%d,num1是%d\n", num, num1);
  num1 = ++num;
  printf("num是%d,num1是%d\n", num, num1);
  num = 5;
  num1 = num++ + ++num;
  printf("num是%d,num1是%d\n", num, num1);
  num1 = num2++ + ++num2;
  printf("num1是%d,num2是%d\n", num1, num2);
  return 0;
}
