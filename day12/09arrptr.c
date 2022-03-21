/*
 数组和指针关系练习
 */
#include <stdio.h>
int main(){
   int arr[] = {1, 2, 3, 4, 5};
   int *p_num = arr, num = 0;
   for (num = 0;num <= 4;num++){
      printf("%d\n", arr[num]);
	  printf("%d\n", p_num[num]);
   }
   printf("sizeof(arr)是%d\n", sizeof(arr));
   printf("sizeof(p_num)是%d\n", sizeof(p_num));
   printf("arr是%p,&arr是%p\n", arr, &arr);
   printf("p_num是%p,&p_num是%p\n", p_num, &p_num);
   for(p_num = arr;p_num <= arr + 4;p_num++){
      printf("%d", *p_num);
   }
   printf("\n");
   return 0;
}
