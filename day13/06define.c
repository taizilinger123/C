/*
 使用宏判断两个整数中最大的哪个
 */
#include <stdio.h>
#define MAX(x,y) (x)>(y)?(x):(y)
int main(){
   int a = 0,b = 0;
   printf("请输入两个整数:");
   scanf("%d%d",&a,&b);
   printf("两个整数中较大的一个是:%d\n",MAX(a,b));
   return 0;
}
