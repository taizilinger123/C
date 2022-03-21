/*
 字符串表示方式演示
 */
#include <stdio.h>
int main(){
   //char str[] = "abc";  "abc\0"和"abc0"一样的
   //char str[3] = "abc";  错误
   char str[] = {'a', 'b', 'c', 0};
   //char str[3] = {'a', 'b', 'c', 0}; 错误
   printf("\"abc\"是%p\n", "abc");
   printf("\"abc\"是%p\n", "abc");
   printf("\"abc\"是%p\n", "a""bc");
   printf("首字符是%c\n", *("abc"));
   //*("abc") = 'x'; 字面值不可以修改,*("abc")意思是取abc的字符串的值'a'首字母
   printf("sizeof(str)是%d\n", sizeof(str));
   printf("str是%p\n", str);
   return 0;
}
