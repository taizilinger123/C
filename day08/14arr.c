/*
  二维数组练习
 */
#include <stdio.h>
int main(){
   /*int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};*/
   int arr[][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
   int row = 0, col = 0;
   arr[1][1] = 6;
   for(row = 0;row <= 2;row++){
      for(col = 0;col <= 3;col++){
	     printf("%d ", arr[row][col]);
	  }
	  printf("\n");
   }
   printf("sizeof(arr)是%d\n", sizeof(arr));
   return 0;
}
