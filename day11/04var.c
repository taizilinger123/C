/*
 作用域演示
 */
#include <stdio.h>
int num; //全局变量
void f(){
  int num3 = 0;
  //printf("%d %d %d %d\n", num, num1, num2, num3); num1和num2不能使用
}
int main(){
  int num1 = 0; //局部变量
  //printf("%d %d %d\n", num, num1, num2); num2不可以使用
  {
     int num2 = 0; //块变量
	 printf("%d %d %d\n", num, num1, num2);
  }
  //printf("%d %d %d\n", num, num1, num2); num2不可以使用
  return 0;
}
