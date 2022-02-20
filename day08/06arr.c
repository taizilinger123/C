/*
  拆分数位练习
 */
#include <stdio.h>
int main(){
   int num = 0, num1 = 0,pos =4;
   int arr[5];
   printf("请输入一个数字：");
   scanf("%d", &num);
   //拆分数字并把拆分结果记录在数组中
   do{
      arr[pos] = num % 10;
	  num /= 10;
	  pos--;
   }while(num);
   //把数组中所有拆分出的数字打印在屏幕上
   for(num1 = pos + 1;num1 <= 4;num1++){
     printf("%d ", arr[num1] );
   }
   printf("\n");
   return 0;
}
