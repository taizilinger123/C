/*
 鸡兔同笼练习
 */
#include <stdio.h>
int main(){
  int num = 0;
  for (num = 0;num <= 40;num++){
     if (4 * num + 2 * (40 - num) == 100){
	    printf("兔子有%d只，鸡有%d只\n",  num, (40 - num));
	 }
  }
  return 0;
}
