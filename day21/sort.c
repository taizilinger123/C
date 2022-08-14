#include <stdio.h>
#include <stdlib.h>
void bubble(int data[],size_t size){
  int i;
  for(i=0;i<size-1;i++){//n个数  n-1轮即可
      int flag = 1;//标识 是否发生过交换
	  int j;
	  for(j=0;j<size-1-i;j++){//-i就是去掉放好的
	     if(data[j]>data[j+1]){//前面的比后面的大
		    int temp = data[j];
			data[j] = data[j+1];
			data[j+1] = temp;
			flag = 0;//发生交换 flag 为0
		 }
	  }
	  if(flag) break;//没有发生交换，不进行下趟
  }
}
int main(){
   int data[] = {9,7,2,4,5,8,1,3,6};
   bubble(data,sizeof(data)/sizeof(data[0]));
   int i;
   for(i=0;i<sizeof(data)/sizeof(data[0]);i++){
      printf("%d\n",data[i]);
   }
}

/*
 root@test:/home/test/biaoc/C/day21# gcc  sort.c
 root@test:/home/test/biaoc/C/day21# ./a.out 
 1
 2
 3
 4
 5
 6
 7
 8
 9
 */
