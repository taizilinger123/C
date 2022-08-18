#include <stdio.h>
#include <stdlib.h>

void bubble(int data[],size_t size){//冒泡排序
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
void insert(int data[],size_t size){//插入排序
  int i;
  for(i=1;i<size;i++){//从第二个到最后一个插入
     int inserted = data[i];//先保存
	 int j;
	 for(j=i;j>0 && inserted<data[j-1];j--){
	    data[j] = data[j-1];//向后移动
	 }
	 if(j!=i) data[j] = inserted;//如果移动了
  }
}
void sel(int data[],size_t size){//选择排序
    //练习:实现选择排序，思路:记录最小数据下标
    int i;
	for(i=0;i<size-1;i++){//选择排序交换位置
	  int min = i;//min代表 最小值的下标
	  int j;
	  for(j=i+1;j<size;j++){//循环拿到最小值下标
	     if(data[j]<data[min]) min = j;
	  }
	  if(min!=i){//找到比data[i]小的了，交换
	     int temp = data[i];
		 data[i] = data[min];
		 data[min] = temp;
	  }
	}
}
int main(){
   int data[] = {9,7,2,4,5,8,1,3,6};
   //bubble(data,sizeof(data)/sizeof(data[0]));
   //insert(data,sizeof(data)/sizeof(data[0]));
   sel(data,sizeof(data)/sizeof(data[0]));
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
