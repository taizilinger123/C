/*
   变量练习
*/
#include <stdio.h>
int main(){
  int num = 54321;
  printf("%d\n", num);
  num = (6 - num % 10) * 10000 + num / 10;
  printf("%d\n", num);
  num = (6 - num % 10) * 10000 + num / 10;
  printf("%d\n", num);
  num = (6 - num % 10) * 10000 + num / 10;
  printf("%d\n", num);
  num = (6 - num % 10) * 10000 + num / 10;
  printf("%d\n", num);
  return 0;
}
