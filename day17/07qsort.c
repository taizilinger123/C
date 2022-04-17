/*
 qsort练习
 */
#include <stdio.h>
#include <stdlib.h>
int comp(const void *p_num1, const void *p_num2){
   const int *p_int1 = (const int*)p_num1;
   const int *p_int2 = (const int*)p_num2;
   if(*p_int1 > *p_int2){
     return 1;
   }
   else if(*p_int1 < *p_int2){
	 return -1;
   }
   else{
     return 0;
   }
}
int main(){
   int num[] = {6, 3, 9, 17, 2, 8, 4}, pos = 0;
   qsort(num, 7, sizeof(int), comp);
   for(pos = 0;pos <= 6;pos++){
     printf("%d ", num[pos]);
   }
   printf("\n");
   return 0;
}
