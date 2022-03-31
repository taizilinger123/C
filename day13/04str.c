/*
 字符串读取演示
 */
#include <stdio.h>
#include <string.h>
int main(){
   char buf[10] = {};
   int num = 0;
   printf("请输入一个字符串：");
   //scanf("%s", buf);
   fgets(buf, 10, stdin);
   if(strlen(buf) == 9 && buf[8] != '\n'){
	  //以下是清理输入缓冲区的内容
      scanf("%*[^\n]");
	  scanf("%*c");
   }
   printf("字符串是%s\n", buf);
   printf("请输入一个整数：");
   scanf("%d", &num);
   printf("整数是%d\n", num);
   return 0;
}
