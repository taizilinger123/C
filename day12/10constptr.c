/*
 const指针练习
 */
#include <stdio.h>
int main(){
  int num = 3;
  const int *p_num = &num;
  //*p_num = 10;
  p_num = NULL;
  int * const p_num1 = &num;
  //p_num1 = NULL;
  *p_num1 = 10;
  return 0;
}
