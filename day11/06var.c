/*
 块变量生命周期演示
 */
#include <stdio.h>
int main(){
  int num = 0;
  for(num = 0;num <= 1;num++){
    {
	  int num1;
	  printf("num1是%d\n", num1);
	  num1 = 3;
	}
	{
	  int num1 = 7;
	  int num2 = 8;
	  int num3 = num1 + num2;
	}
  }
  return 0;
}
