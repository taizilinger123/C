/*
 地址相关操作符练习
 */
#include <stdio.h>
int main(){
  int num = 3;
  printf("&num是%p\n", &num);
  *(&num) = 7;
  printf("num是%d\n", num);
  return 0;
}
