/*
   break;演示练习
 */
#include <stdio.h>
int main() {
   int num = 0;
   for(num=0;num <= 9;num++){
      printf("%d", num);
	  if (num == 4){
	     break;
	  }
   }
   printf("\n");
   return 0;
}
