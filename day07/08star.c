/*
   循环嵌套练习
 */
#include <stdio.h>
int main(){
   int num1 = 0, num2 = 0;
   for(num1 = 0;num1 <=4;num1++){
     for(num2 = 0;num2 <= num1;num2++){
	    printf("*");
	 }
	 printf("\n");
   }
   return 0;
}
