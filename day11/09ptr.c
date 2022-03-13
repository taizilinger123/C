/*
   指针练习
   */
#include <stdio.h>
int main(){
  int num = 0;
  int *p_num = NULL;
  p_num = &num;
  *p_num = 4;
  printf("*p_num是%d,num是%d\n", *p_num, num);
  return 0;
}
