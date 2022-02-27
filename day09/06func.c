/*
 函数练习
 */
#include <stdio.h>
#include <stdlib.h>
void f(){
    printf("1\n");
	exit(0);
	//return ;
	printf("2\n");
}
int main(){
    f();
	printf("3\n");
    return 0;
}
