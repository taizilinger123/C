#include <stdio.h>

int main(int argc, char *argv[])
{
   //字符，原则上'',内部只有一个字符，转义字符除外
   //char a = 'abc';//不合理

   //转义字符，由反斜杠\组成的多个字符
   char ch = '\n';//换行符
   printf("ffff%c",ch);

   ch = '\r';//光标切换到句首
   printf("abcddd%cefg\n", ch);
   
   ch = '\b';//退格
   printf("12%c3456\n", ch);
   
   return 0;


}
