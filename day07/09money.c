/*
   货币练习
 */
#include <stdio.h>
int main(){
  int num1 = 0, num2 = 0;
  for(num1 = 0;num1 <= 2;num1++){
      for(num2 = 0;num2 <= (10 - 5 * num1)/2;num2++){
         printf("5元钱一共有%d张，2元钱一共有%d张，1元钱一共有%d张\n", num1, num2,10 - 5*num1 - 2*num2);
      }
  }
  return 0;
}
