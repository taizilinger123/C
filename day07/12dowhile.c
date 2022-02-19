/*
  do...while练习
 */
#include <stdio.h>
int main(){
   int num = 0;
   do {
      printf("请输入一个数字：");
	  scanf("%d", &num);
   }while (num != 0);
   return  0;
}
