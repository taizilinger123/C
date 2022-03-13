/*
 指针练习
 */
#include <stdio.h>
int main(){
  int num = 300;
  int *p_num = &num;
  printf("*p_num是%d\n", *p_num);
  printf("*(char*)p_num是%d\n", *(char*)p_num);
  return 0;
}
