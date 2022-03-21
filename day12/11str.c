/*
 字符串表示方式演示
 */
#include <stdio.h>
int main(){
   printf("\"abc\"是%p\n", "abc");
   printf("首字符是%c\n", *("abc"));
   //*("abc") = 'x'; 字面值不可以修改
   return 0;
}
