/**
   变量练习
    */
#include <stdio.h>
int main(){
   int num = 1;
   printf("%d X %d = %d\n", num, 10 - num, num * (10 - num));
   num = num + 1; //num++;
   printf("%d X %d = %d\n", num, 10 - num, num * (10 - num));
   num = num + 1;
   printf("%d X %d = %d\n", num, 10 - num, num * (10 - num));
   num = num + 1;
   printf("%d X %d = %d\n", num, 10 - num, num * (10 - num));
   num = num + 1;
   printf("%d X %d = %d\n", num, 10 - num, num * (10 - num));
   return 0;
}
