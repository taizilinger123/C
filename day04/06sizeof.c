/*
   sizeof练习
 */
#include <stdio.h>
int main(){
   char ch = 0;
   printf("sizeof(char)是%d\n", sizeof(char));
   printf("sizeof(ch)是%d\n", sizeof(ch));
   sizeof(ch = 10);
   printf("ch是%hhd\n",  ch);
   return 0;
}
