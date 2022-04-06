/*
 乘法宏练习
 */
#include <stdio.h>
#define MUL(x,y)   ((x) * (y))
int main(){
   printf("MUL(2 + 3, 7 - 5)是%d\n", MUL(2 + 3, 7 - 5));
   printf("20 / MUL(2, 5)是%d\n", 20 / MUL(2, 5));
   return 0;
}
