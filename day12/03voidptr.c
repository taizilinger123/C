/*
 void*指针练习
 */
#include <stdio.h>
int main(){
 int num = 5;
 void *p_num = &num;
 //printf("*p_num是%d\n", *p_num);
 printf("*(int*)p_num是%d\n", *(int *)p_num);
 return 0;
}
