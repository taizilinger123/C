/*
   二维数组练习
 */
#include <stdio.h>
int main(){
  int num[5][5] = {};
  int row = 0, col = 0;
  for(row = 0;row <= 4;row++){
      for(col = 0;col <= 4;col++){
	      num[row][col] = row + 1;
	  }
  }
  for(row = 0;row <= 4;row++){
      for(col = 0;col <= 4;col++){
	      printf("%d", num[row][col]);
	  }
      printf("\n");
  }
  return 0;
}
