/*
 彩票程序升级版
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
   int lottery[7] = {}, num = 0, tmp = 0, pos = 0;
   srand(time(0));
   while(num < 7){
       tmp = rand() % 36 + 1; 
	   for(pos = 0;pos <= num - 1;pos++){
	       if(tmp == lottery[pos]){
		       break;
		   }
	   }
	   if (!(pos <= num - 1)){
	     lottery[num] = tmp;
		 num++;
	   }
   }
   for(pos = 0;pos <= 6;pos++){
      printf("%d ", lottery[pos]);
   }
   printf("\n");
   return 0;
}
