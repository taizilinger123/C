/*
 函数指针练习
 */
#include <stdio.h>
int add(int x, int y){
    return x + y;
}
int main(){
   int (*p_Func)(int, int) = NULL;
   printf("add是%p\n", add);
   p_Func = add;
   printf("p_Func(3, 8)是%d\n", p_Func(3, 8));
   return 0;
}
