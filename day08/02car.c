/*
   车轮子练习
 */
#include <stdio.h>
int main(){
   int num = 0, num1 = 0;
   for(num = 0;num <= 7;num++){
       for(num1 = 0;num1 <= (28 - 4 * num)/3;num1++){
	      if(28 == (4 * num + 3 * num1 + 2 * (10 - num - num1))){
			  printf("汽车有%d辆，三轮车有%d辆，自行车有%d辆\n", num, num1, 10 - num - num1);
		  }  
	   }
   }
   return 0;
}
