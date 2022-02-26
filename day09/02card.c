/*
 身份证校验码
 */
#include <stdio.h>
int main(){
   int  num[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
   int code[] = {1, 0, -1, 9, 8, 7, 6, 5, 4, 3, 2};
   int card[17] = {};
   int pos = 0, sum = 0;
   for (pos = 0;pos <= 16;pos++){
       printf("请输入一个数字：");
	   scanf("%d", &card[pos]);
	   //scanf("%d", card + pos);  数字名称+数组下标
   }
   for (pos = 0;pos <= 16;pos++){
      sum += num[pos] * card[pos];
   }
   //code[sum % 11] == -1 ? 'X' : '0' + code[sum % 11];
   if (code[sum % 11] == -1){
       printf("校验码是X\n");
   }
   else {
       printf("校验码是%d\n", code[sum % 11]);
   }
   return 0;
}
