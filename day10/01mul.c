/*
  函数练习
 */
#include <stdio.h>
void show(int num, int num1){
    printf("%d X %d = %d\n",  num, num1, num * num1);
}
int main(){
  int num = 0;
  for(num = 1;num <= 5;num++){
      show(num,  10 - num);
  }
  return 0;
}
