/*
  数组练习  
 */
#include <stdio.h>
int main(){
   int num = 0;
   int arr[3]; //数组声明语句
   arr[0] = 1;
   printf("arr[0]是%d\n", arr[0]);
   for(num = 0;num <= 2;num++){
      arr[num] = 0;
   }
   for(num = 0;num <= 2;num++){
      printf("%d ", arr[num]);
   }
   printf("\n");
   return 0;
}
