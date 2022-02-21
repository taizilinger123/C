/*
   数组练习
 */
#include <stdio.h>
int main(){
   int arr[8] = {}, num = 0, num1 = 0, num2 = 0;
   //0到7次数
   for(num = 0;num <= 7;num++){
       printf("请输入一个数字: ");
	   scanf("%d", &arr[num]);
   }
   //0到7数组下标
   for(num = 0;num <= 7;num++){
      if(arr[num] > 0){
	     num1++;
	  }
	  else if (arr[num] < 0){
	     num2++;
	  }
   }
   printf("正数的个数是%d,负数的个数是%d\n", num1, num2);
   return 0;
}
