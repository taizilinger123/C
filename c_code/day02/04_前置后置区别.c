#include <stdio.h>

int main(int argc, char *argv[])
{
   int a = 1;
   int b = 0;
   
   //后置++
   b = a++;
   printf("a = %d, b = %d\n", a, b);


   a = 1;
   b = 0;
   
   //前置++,在加后用
   b = ++a;
   printf("a2 = %d, b2 = %d\n", a, b);

   a = 1;
   b = 0;

   a++;
   b = a;
   printf("a3 = %d, b3 = %d\n", a, b);

   return 0;


}
