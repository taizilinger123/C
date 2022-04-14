/*
 堆练习
 */
#include <stdio.h>
#include <stdlib.h>
void destroy(int **pp_num){
      free(*pp_num);
      *pp_num = NULL;
}
int main(){
   int *p_num = (int*)malloc(4 * sizeof(int));
   if (p_num) {
	   destroy(&p_num);
	   printf("p_num是%p\n", p_num);
   }
   return 0;
}
