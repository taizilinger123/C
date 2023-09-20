#include <stdio.h>
//线性查找，成功返回对应下标，失败返回-1
int line_find(int data[],size_t size,int key){
  int i;
  for(i=0; i<size; i++){
     if(data[i] == key){
	    return i;
	 }
  } 
  return -1;
}
int half_find(int data[],size_t size,int key)
{//二分查找，只能用于有序数组
   int left = 0; int right = size-1;
   while(left <= right){
      int mid = (left+right)/2;
	  if(key<data[mid])//小于去前半部分
		right = mid-1;//前一半
	  else if(key>data[mid])
		left = mid+1;
	  else return mid;
   }
   return -1;
}
int main(){
   /*int data[] = {1,2,5,6,7,4,8,9,3};//无序数组
   size_t size = sizeof(data)/sizeof(data[0]);//数组的长度
   int key = 7;//查找7
   int res = line_find(data, size, key);*/
   int data[] = {1,2,3,4,5,6,7,8,9};//有序数组
   size_t size = sizeof(data)/sizeof(data[0]);//数组的长度
   int key = 7;//查找7
   int res = half_find(data, size, key);
   if(res == -1){
       printf("没有找到\n");
   }else{
       printf("找到了，在%d处\n",res);
   }
   return 0;
}
