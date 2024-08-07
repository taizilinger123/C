#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void quick(int data[],size_t left, //快速排序
  size_t right){//size被左右边界替代
   size_t p = (left+right)/2;//以中间做基准
   int pivot = data[p]; //存储基准数
   size_t i = left,j = right;
   while(i<j){//i j没碰面继续找，相等退出
      for(;!(i>=p || pivot<data[i]);i++);//移动i
	  if(i<p){
	     data[p] = data[i];
		 p = i;
	  }
	  for(;!(j<=p || pivot>data[j]);j--);//移动j
	  if(j>p){
	    data[p] = data[j];
		p = j;
	  }
   }
   data[p] = pivot;
   if((p-left)>1)//左边元素个数大于1
	 quick(data,left,p-1);
   if((right-p)>1)
	 quick(data,p+1,right);
}
//3数组归并 外部归并
void outer_merge(int data1[],size_t size1,
  int data2[],size_t size2,int data3[]){
  int i=0,j=0,k=0;
  for(;;){
     if(i<size1 && j<size2){//双方供货
	    if(data2[j]<data1[i])
		  data3[k++] = data2[j++];
		else data3[k++] = data1[i++];
	 }else{//单方供货
	    if(i<size1) data3[k++] = data1[i++];
		else if(j<size2) data3[k++] = data2[j++];
		else break;//归并已经完成
	 }
  }
}
//单数组归并，内部归并(由两个有序子数组组成)
void inner_merge(int data[],size_t left,
  size_t mid,size_t right){//开始/分隔/结束下标
   size_t size = (right-left+1)*sizeof(int);
   int* merge = malloc(size);//临时存储排序数据
   outer_merge(data+left,mid-left+1,
	  data+mid+1,right-mid,merge);
   memcpy(data+left,merge,size);//内存拷贝
   free(merge);
}
void merge(int data[],size_t left,//归并排序 
  size_t right){
  if(left<right){
    int mid = (left+right)/2;
	merge(data,left,mid);//left到mid有序
	merge(data,mid+1,right);//mid+1到right有序
	//data已经变成2个有序的子数组，可以使用内部归并了
	inner_merge(data,left,mid,right);
  }
}
int main(){
   int data[] = {9,7,2,4,5,8,1,3,6};
   //bubble(data,sizeof(data)/sizeof(data[0]));
   //insert(data,sizeof(data)/sizeof(data[0]));
   //sel(data,sizeof(data)/sizeof(data[0]));
   //quick(data,0,sizeof(data)/sizeof(data[0])-1);
   /*int data1[] = {1,3,5,7,9,10};
   int data2[] = {2,4,6,8};
   int data[10];
   outer_merge(data1,6,data2,4,data);*/
   merge(data,0,8);
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
