#include <stdio.h>

int main(int argc, char *argv[])
{

   printf("mike = %s\n", "sb");

   int a = 10;
   printf("&a = %p\n", &a);

   //%%在屏幕输出一个%,后面的d也会输出
   printf("%%d\n");

   a = 123;
   printf("a1 = %d\n", a);
   
   //%5d, 以5个字符输出，没有的字符以空字符填充，默认是右对齐
   printf("a2 = '%5d'\n",a);   

   return 0;


}
