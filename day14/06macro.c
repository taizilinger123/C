/*
 宏练习
 */
#include <stdio.h>
#define INC(n)   n++
void inc(int num){
   num++;
}
int main(){
  int num = 0;
  inc(num);
  printf("num是%d\n", num);
  INC(num);
  printf("num是%d\n", num);
  return 0;
}
