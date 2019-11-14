#include <stdio.h>

int main(int argc, char *argv[])
{  
   char ch = 'a';
   printf("ch1 = %c, ch = %d\n", ch, ch);
 
   ch = 97;//以ascii赋值，和ch = 'a'等价的
   printf("ch2 = %c\n", ch);   

   //小写字母比大写字母大32
   char a = 'A';
   char b = 'a';
   printf("A = %d, a = %d\n", a, b);   
   
   //小写转大写，小写字母-32
   printf("小写转大写: %c\n", 'a' - 32);
   
   //大写转小写，大写字节+32
   printf("大写转小写: %c\n", 'A' + 32);
   
   char tmp;
   printf("请输入字符: ");
   scanf("%c",&tmp);
   printf("tmp = %c\n", tmp); 
   
   return 0;


}
