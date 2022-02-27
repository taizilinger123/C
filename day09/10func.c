/*
 函数练习
 */
#include <stdio.h>
double add(double, double);
int main(){
  int num = add(2, 4);
  printf("num是%d\n", num);
  return 0;
}
/*int add(int num, int num1){
    return num + num1;
}*/
double add(double num, double num1){
   return num + num1;
}
