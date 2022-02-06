/*
   类型转换练习
 */
#include <stdio.h>
int main(){
   float fvalue = 1.2f;
   int num = fvalue;
   printf("sizeof(1 ? 1 : 0.9)是%d\n", sizeof(1?1:0.9));
   printf("-7 + 3 > 0是%d\n", -7 + 3 > 0);
   printf("-7 + 3u > 0是%d\n", -7 + 3u > 0);
   printf("fvalue是%d\n", (int)fvalue);
   printf("fvalue是%g\n", fvalue);
   printf("num是%d\n", num);
   return 0;
}
