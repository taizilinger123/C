/*
   二维数组练习   
 */
#include <stdio.h>
int main(){
   int num[5][5] = {};
   int row = 0, pos = 0;
   for(pos = 0;pos <= 3;pos++){
       num[0][pos] = 1;
   }
   for(pos = 0;pos <= 3;pos++){
       num[pos][4] = 2;
   }
   for(pos = 1;pos <= 4;pos++){
       num[4][pos] = 3;
   }
   for(pos = 1;pos <= 4;pos++){
       num[pos][0] = 4;
   }
   for (row = 0;row <= 4;row++){
      for(pos = 0;pos <= 4;pos++){
	      if (num[row][pos]){
		      printf("%d", num[row][pos]);
		  }
		  else {
		      printf(" ");
		  }
	  }
	  printf("\n");
   }
   return 0;
}

