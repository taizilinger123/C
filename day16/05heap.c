/*
 堆中变量的使用
 */
#include <stdio.h>
#include <stdlib.h>
int main(){
  int *p_num = (int *)malloc(10 * sizeof(int));
  if (p_num) {
     printf("分配成功\n");
	 free(p_num);
	 //free(p_num + 5);//已放弃 (核心已转储)), *** Error in `./a.out': free(): invalid pointer: 0x0000000001c95024 ***
	 //free(p_num);  //已放弃 (核心已转储)), *** Error in `./a.out': double free or corruption (fasttop): 0x0000)'
	 p_num = NULL;
  }
  return 0;
}
