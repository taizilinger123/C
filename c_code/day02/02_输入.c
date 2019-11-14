#include <stdio.h>

int main(int argc, char *argv[])
{
   char a;
   printf("请输入字符a:");
   //scanf("%c", &a);
   a = getchar();//读取键盘的字符，放在a变量
   printf("a = '%c'\n", a);

   return 0;


}




int main01(int argc, char *argv[])
{
   int a;
   printf("请输入a:");
   scanf("%d", &a);
   printf("a = %d\n", a);

   int b;
   int c;
   printf("请输入b, c:");
   scanf("%d %d", &b, &c);
   printf("b = %d, c = %d\n", b, c);

   return 0;


}
