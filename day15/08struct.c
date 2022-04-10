/*
 结构体练习
 */
#include <stdio.h>
typedef struct {
   char ch; //1
   int num; //4
} stru;
typedef struct {
   short num;
   char ch;
} stru1;
int main(){
   printf("sizeof(stru)是%d\n", sizeof(stru));
   printf("sizeof(stru1)是%d\n", sizeof(stru1));
   return 0;
}
