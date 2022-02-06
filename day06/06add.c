/*
   三目操作符练习
 */
#include <stdio.h>
int main(){
 int num1 = 0, num2 = 0, num = 0;
 char ch = 0;
 printf("请输入计算公式：");
 scanf("%d %c %d", &num1, &ch, &num2);
 num = ch == '+' ? num1 + num2 : num1 - num2;
 printf("计算结果是%d\n", num);
 return 0;
}
