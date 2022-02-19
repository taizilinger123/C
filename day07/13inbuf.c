/*
   输入缓冲区练习 
 */
#include <stdio.h>
int main(){
   int num = 0;
   printf("请输入一个数字：");
   while(!scanf("%d", &num)){
          scanf("%*[^\n]");
		  scanf("%*c");
		  printf("请再输入数字:");
   }
   scanf("%*[^\n]");
   scanf("%*c");
   printf("num是%d\n", num);
   printf("请输入一个数字：");
   scanf("%d", &num);
   printf("num是%d\n", num);
   return  0;
}
