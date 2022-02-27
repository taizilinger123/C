/*
 函数练习
 */
#include <stdio.h>
int add(int num, int num1){
   return num + num1;
}
void print(int num){
   printf("%d\n", num);
}
int read(void){
   int num = 0;
   printf("请输入一个数字：");
   scanf("%d", &num);
   return num;
}
int main(){
   int num = 0;
   num = add(2, 3);
   printf("num是%d\n", num);
   print(num);
   num = read();
   num = add(num, 4);
   printf("num是%d\n", num);
   print(num);
   return 0;
}
