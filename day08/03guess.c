/*
   猜数游戏
 */
#include <stdio.h>
int main(){
	int guess, num = 0;
	guess %= 100;
	printf("要猜测的数字是%d\n", guess);
	do{
	   printf("请猜测一个数字：");
	   scanf("%d", &num);
	   if(num > guess){
		   printf("你猜大了\n");
	   } 
	   else if(num < guess){
	       printf("你猜小了\n");   
	   }
	   else {
	       printf("你真聪明\n");
	   }
	}while(num != guess);
    return 0;
}
