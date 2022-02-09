/*
 季节练习
 */
#include <stdio.h>
int main(){
   int season = 0;
   printf("请输入季节：");
   scanf("%d", &season);
   switch(season % 4) {
   case 0:
	   printf("春天\n");
	   break;
   case 1:
	   printf("夏天\n");
	   break;
   case 2:
	   printf("秋天\n");
	   break;
   case 3:
	   printf("冬天\n");
	   break;
   default:
	   printf("你有病吧\n");
	   break;
   }
   return 0;
}
