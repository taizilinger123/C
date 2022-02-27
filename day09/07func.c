/*
 函数练习
 */
#include <stdio.h>
int add(int num, int num1){
   return num + num1;
}
int main(){
   int num = 0;
   num = add(2, 3);
   printf("num是%d\n", num);
   return 0;
}
