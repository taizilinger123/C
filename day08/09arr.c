/*
 数组练习
  2.求出每一位个系数
个：num%10
十：num/10%10
百：num/100%10
千：num/1000%10
万：num/10000%10
 */
#include <stdio.h>
int main(){
  int arr[10] = {}, num = 0, num1 = 0;
  printf("请输入一个数字：");
  scanf("%d", &num);
  do{
	 //num % 10取余就是那个个位数上的那个值，++代表哪个数出现的次数
     arr[num % 10]++;  //把当前哪个个位数上出现的数字加一,arr[num % 10]表示哪个出现的数字
	 num /= 10; //个数处理完了不需要用了，丢掉 
  }while(num);
  for(num1 = 0;num1 <= 9;num1++){
     printf("数字%d出现的次数是%d\n", num1, arr[num1]);
  }
  return 0;
}
