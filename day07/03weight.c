/*
 砝码练习
 */
#include <stdio.h>
int main(){
   int num = 0, last = 0;
   for(num = 1;num <= 100;num++){
      if(2 * last - 1 < num){
           printf("%d ", num);
		   last = num;
	  }	       
   }
   printf("\n");
   return 0;
}
