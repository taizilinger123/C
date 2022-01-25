/*
   自增，自减操作符练习
 */
#include <stdio.h>
int main(){
  int num = 0;
  num++;
  printf("num是%d\n", num);
  num--;
  printf("num是%d\n", num);
  //3++;  只能对变量进行操作
  ++num;
  printf("num是%d\n", num);
  --num;
  printf("num是%d\n", num);
  return 0;
}
