/*
 数组做形参练习
 */
#include <stdio.h>
//数组的形参num[], size是数组的个数
void neg(int num[], int size){
    int pos = 0; //pos是下标
	for(pos = 0;pos <= size - 1;pos++){
	   num[pos] = 0 - num[pos];
	}
}
int main(){
  int num[] = {-4, 3, 9}, pos = 0;
  neg(num, 3);
  for(pos = 0;pos <= 2;pos++){
     printf("%d ", num[pos]);
  }
  printf("\n");
  return 0;
}
