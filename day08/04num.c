/*
   统计数位个数练习
 */
#include <stdio.h>
int main(){
   int num = 0, result = 0;
   printf("请输入一个数字：");
   scanf("%d", &num);
   do{
	   num /= 10;
	   result++;
   }while(num);
   printf("一共有%d个数位\n",  result);
   return 0;
}
