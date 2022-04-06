/*
 宏操作符练习
 */
#include <stdio.h>
#define STR(n)     #n
#define GLOBAL(n)  g_##n
#define PTR(n)     p_##n
int GLOBAL(num);  //int g_num;
int main(){
   int *PTR(num) = NULL; //int *p_num =
   printf(STR(2 + 3)"\n"); //printf("2 + 3""\n");
   printf(STR(printf())"\n");//printf("printf()""\n");
   return 0;
}


