/*
 指针四则计算
 */
#include <stdio.h>
int main(){
  int num = 0, num1 = 0;
  int *p_num = &num, *p_num1 = &num1;
  printf("p_num是%p,p_num1是%p\n", p_num, p_num1);
  printf("p_num + 3是%p\n", p_num + 3);
  printf("p_num1 - 2是%p\n", p_num1 - 2);
  printf("p_num - p_num1是%d\n", p_num - p_num1);
  return 0;
}
