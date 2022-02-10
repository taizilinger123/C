/*
 根据年和月计算天数练习
 */
#include <stdio.h>
int main(){
   int year = 0, month = 0;
   printf("请输入年和月：");
   scanf("%d %d", &year, &month);
   if (month == 1 || month == 3 || 
	   month == 5 || month == 7 ||
	   month == 8 || month == 10 ||
	   month == 12){
       printf("一共有31天\n");
   }
   else if (month == 4 || month == 6 ||
		   month == 9 || month ==11){
       printf("一共有30天\n");
   }
   else {
       if ((!(year % 400))||(!(year % 4)&&(year % 100))) {
	       printf("一共有29天\n");
	   } 
	   else {
	       printf("一共有28天\n");
	   }
   }
   return 0;
}
