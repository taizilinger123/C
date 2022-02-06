/*
 绝对值练习
 */
#include <stdio.h>
int main(){
  int num = 0;
  printf("请输入一个整数：");
  scanf("%d", &num);
  num = num & (1 << 31)? 0 - num : num;
  printf("绝对值是%d\n", num);
  return 0;
}
