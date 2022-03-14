/*
  打印图形练习 
 */
#include <stdio.h>
int main(){
  int num = 0, num1 = 1;
  int *p_num = NULL, *p_num1 = NULL;
  p_num = &num;
  p_num1 = &num1;
  for(*p_num = 1;*p_num <= 12345;*p_num = 10 * *p_num + *p_num1){
      printf("%d\n", *p_num);
	  (*p_num1)++;
  }
  /*for(num = 1;num <= 12345; num = 10 * num + num1){
     printf("%d\n", num);
	 num1++;
  }*/
  return 0;
}
