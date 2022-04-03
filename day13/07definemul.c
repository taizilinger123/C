/*
 计算两个整数的乘积
 */
#include <stdio.h>
#define MUL(x,y) ((x)*(y)) //每个参数加括号，整个表达式外面加括号，仅保证运算顺序
int main(){
   //printf("结果:%d\n",MUL(3,5));
   //printf("结果:%d\n",MUL(1+2,2+3));
   printf("结果:%d\n",30/MUL(3,5));
   return 0;
}
