/*
 联合练习
 */
#include <stdio.h>
typedef union {
      char ch[2];
	  int num;
} un;
int main(){
   un un1;
   un1.num = 0;
   un1.ch[0] = 'a';
   printf("num是%d\n", un1.num);
   printf("sizeof(un)是%d\n", sizeof(un));
   return 0;
}
