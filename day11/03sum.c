/*
 用递归求累加练习
 */
#include <stdio.h>
int sum(int num){
   if (num == 1){
      return 1;
   }
   else {
      return num + sum(num -1);
   }
}
int main(){
   int num = 0;
   printf("请输入一个整数：");
   scanf("%d", &num);
   printf("求和结果是%d\n", sum(num));
   return 0;
}
