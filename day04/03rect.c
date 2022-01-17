/*
   求矩形面积的练习
 */
#include <stdio.h>
int main(){
   int length = 0, width = 0;
   printf("请输入矩形的长和宽：");
   scanf("%d %d", &length, &width);
   printf("矩形面积是%d\n", length * width);
   return 0;
}
