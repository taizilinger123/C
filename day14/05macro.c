/*
 宏练习
 */
#include <stdio.h>
#define  MAX(x,y)  x > y ? x : y
#define  HEX(n)    '0' <= n && n <= '9'? n  - '0' : n - 'a' + 10   
int main(){
  printf("MAX(3,7)是%d\n", MAX(3,7));
  printf("HEX(\'d\')是%d\n", HEX('d'));
  return 0;
}
