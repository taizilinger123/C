/*
 指针形参练习
 */
#include <stdio.h>
void swap(int *p_num, int *p_num1){
   *p_num += *p_num1; // *p_num = 3, *p_num1 = 7, *p_num = *p_num + *p_num1 = 3 + 7 = 10 
   *p_num1 = *p_num - *p_num1; // *p_num1 = *p_num - *p_num1 = 10 - 7 = 3 
   *p_num = *p_num - *p_num1;  // *p_num = *p_num - *p_num1 = 10 - 3 = 7 
}
int main(){
  int num = 3, num1 = 7;
  swap(&num, &num1);
  printf("num是%d, num1是%d\n", num, num1);
  return 0;
}
