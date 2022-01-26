/*
 布尔类型练习
 */
#include <stdio.h>
#include <stdbool.h>
int main(){
  bool bl = true;
  int num = 0;
  printf("bl是%d\n", bl);
  bl = false;
  printf("bl是%d\n", bl);
  printf("3 == 5是%d\n", 3 == 5);
  printf("3 != 5是%d\n", 3 != 5);
  printf("!6是%d\n", !6);
  num = 3 != 2 + 1;
  printf("num是%d\n", num);
  num = 7;
  0 && ++num;
  printf("num是%d\n", num);
  1 || ++num;
  printf("num是%d\n", num);
  return 0;
}
