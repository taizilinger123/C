/*
 考试成绩练习
 */
#include <stdio.h>
int main(){
   int rank = 0;
   printf("请输入一个考试成绩：");
   scanf("%d", &rank);
   if ((rank >= 90) && (rank <= 100)) {
	   printf("优\n");
   }
   else if ((rank >= 80) && (rank <= 89)) {
       printf("良\n");
   }
   else if ((rank >= 70) && (rank <= 79)) {
       printf("中\n");
   }
   else if ((rank >= 60) && (rank <= 69)) {
       printf("差\n");
   }
   else {
       printf("不及格\n");
   }
   return 0;
}
