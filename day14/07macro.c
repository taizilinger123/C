/*
 宏练习
 */
#include <stdio.h>
#define NEG(n)   (0 - (n))
int main(){
   printf("5 - NEG(5)是%d\n", 5 - NEG(5));
   printf("NEG(2 + 3)是%d\n", NEG(2 + 3));
   return 0;
}
