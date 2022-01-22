/*
   时间练习
 */
#include <stdio.h>
int main(){
   int secs = 0, num = 0;
   printf("请输入一个秒数：");
   scanf("%d", &secs);
   num = secs % 60;
   printf("     :%02d\r", num);
   secs = secs / 60;
   num = secs % 60;
   printf("  :%02d\r", num);
   secs = secs /  60;
   num = secs % 24;
   printf("%02d\n", num);
   return 0;
}
