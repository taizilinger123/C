/*
 宏练习
 */
#include <stdio.h>
#define PI   3.14f
int main(){
  int radius = 0;
  const float pi = 3.14f;
  printf("请输入圆的半径: ");
  scanf("%d", &radius);
  printf("周长是%g\n", 2*PI*radius);
  printf("周长是%g\n", 2*pi*radius);
  return 0;
}
