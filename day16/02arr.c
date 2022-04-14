/*
 数组名称地址演示
 */
#include <stdio.h>
int main(){
  int num[] = {1, 2, 3, 4, 5};
  printf("num是%p,&num是%p\n", num, &num);
  printf("(&num)[0][3]是%d\n", (&num)[0][3]);
  //printf("num[0][3]是%d\n", num[0][3]);
  return 0;
}
