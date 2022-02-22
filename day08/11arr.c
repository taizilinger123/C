/*
 变长数组练习
 */
#include <stdio.h>
int main(){
   int num = 0;
   printf("请输入一个数字：");
   scanf("%d", &num);
   int  arr[num] = {}; //变长数组不可以初始化
   return 0;
}
