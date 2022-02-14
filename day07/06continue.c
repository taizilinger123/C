/*
  continue演示练习
 */
#include <stdio.h>
int main(){
   int num = 0;
   for(num = 0;num <= 9; num++){
	 if (num == 3 || num == 6){
	     continue;
	 }
     printf("%d", num);
   }
   printf("\n");
   return 0;
}
