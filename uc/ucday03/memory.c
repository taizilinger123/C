#include <stdio.h>
#include <stdlib.h>

int  i1 = 10;//全局区
int  i2 = 20;//全局区
int  i3;//bss
static int i4 = 40;//全局
const int i5 = 50;//只读常量区
void fa(int i6){//栈
	int i7 = 70;//栈
	static int i8 = 80;//全局
	const int i9 = 90;//栈
	int* pi = malloc(4);//堆
	char* st1 ="abcdef";//只读常量
	char st2[] = "abcdef";//栈,在栈中复制了字符串的内容
    printf("i6=%p\n",&i6);
    printf("i7=%p\n",&i7);
    printf("i8=%p\n",&i8);
    printf("i9=%p\n",&i9);
    printf("pi=%p\n",pi);
    printf("st1=%p\n",st1);
    printf("st2=%p\n",st2);
}
int main(){
    printf("i1=%p\n",&i1);
    printf("i2=%p\n",&i2);
    printf("i3=%p\n",&i3);
    printf("i4=%p\n",&i4);
    printf("i5=%p\n",&i5);
    fa(100);
    printf("fa=%p\n",fa);//代码区
}
