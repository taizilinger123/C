/*
 判断素数的函数练习
 */
#include <stdio.h>
#include <stdbool.h>
bool su(int num){
	int num1 = 0;
	for(num1 = 2;num1 <= num - 1;num1++){
	   if(!(num % num1)){
	       return  false;
	   }
	}
	return true;
}
int main(){
   int num = 0;
   printf("请输入一个数字：");
   scanf("%d", &num);
   //printf("判断结果是%d\n", su(num));
   printf(su(num)? "是素数\n":"不是素数\n");
   return 0;
}
