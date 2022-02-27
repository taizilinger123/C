/*
  形式参数练习
 */
#include <stdio.h>
//形参
void f(int num){
  num++;
}
int main(){
   int num = 0;
   f(num); //实参
   printf("num是%d\n", num);
   return 0;
}
