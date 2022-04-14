/*
 二级指针练习
 */
#include <stdio.h>
int main(){
   int num = 0;
   int *p_num = &num;
   int **pp_num = &p_num;
   printf("pp_num是%p,*pp_num是%p,**pp_num是%d\n",pp_num,
		   *pp_num,**pp_num);
   printf("pp_num[0][0]是%d\n", pp_num[0][0]);
   return 0;
}
