/*
  for练习
 */
#include <stdio.h>
int main(){
  int num = 0, num1 = 0;
  //省略大括号,大括号内只有一条语句
  /*for(num = 1;num <= 3;num++)
     printf("%d\n", num);*/

  //使用,操作符
  /*for(num = 1, num1 = 9; num <= num1;num++,num1--){
      printf("%d X %d = %d\n", num, num1, num * num1);
  }*/
  
  //临时定义循环变量gcc -std=c99  10for.c
  /*for(int num2 = 0;num2 <= 3;num2++){
      printf("%d", num2);
  }
  //printf("num2是%d\n",  num2); 错误
  printf("\n");*/
  
  //小括号中只保留逻辑表达式
  /*for(;num <= 3;){
      printf("num是%d\n", num);
	  num++;
  }*/

  //空语句
  //for(num = 0;num <= 3;num++);
  //死循环
  for(;;);
  return 0;
}
