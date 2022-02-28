/*
 二维数组填充练习
 */
#include <stdio.h>
void fill(int num[],  int size, int val){
   int num1 = 0;
   for(num1 = 0;num1 <= size - 1;num1++){
      num[num1] = val;
   }
}
int main(){
	int arr[5][5] = {}, num = 0, num1 = 0;
	for(num = 0;num <= 4;num++){
	    fill(arr[num], 5, num +1);
	}
	for(num = 0;num <= 4;num++){
	  for(num1 = 0;num1 <= 4;num1++){
	      printf("%d", arr[num][num1]);
	  }
	  printf("\n");
	}
   return 0;
}
