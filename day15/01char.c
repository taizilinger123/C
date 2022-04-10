/*
   字符变量大小写转换练习
 */
#include <stdio.h>
#define  CHAR(ch)  ((ch) >= 'a' && (ch) <= 'z' ? (ch) - 'a' + 'A' : (ch) - 'A' + 'a') 
int main(){
   char ch = 0;
   printf("请输入一个字符: ");
   scanf("%c", &ch);
   printf("转换结果是%c\n", CHAR(ch));
   return 0;
}
