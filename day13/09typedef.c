/*
 结构体的对齐和补齐
 */
#include <stdio.h>
struct test1
{
   int i;
   short s;
   char c;
   double d;
};
struct test2
{
   char c1;
   short s;
   char c2;
};
int main(){
   printf("sizeof(test1)=%d\n",sizeof(struct test1));
   printf("sizeof(test2)=%d\n",sizeof(struct test2));
   return 0;
} 
