/*
 const练习
 */
#include <stdio.h>
int main(){
  const int num = 3;
  //num = 7; //const修饰的num不能赋值
  int *p_num = &num;
  *p_num = 7;
  return 0;
}
