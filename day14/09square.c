/*
 平方宏练习
 */
#include <stdio.h>
#define SQUARE(n)  ((n)*(n))
int main(){
  int num = 6;
  printf("SQUARE(++num)是%d\n", SQUARE(++num));
  return 0;
}
