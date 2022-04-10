/*
枚举练习
*/
#include <stdio.h>
int main(){
	enum {MALE, FEMALE};
	int num = 0;
	printf("请输入一个数字: ");
	scanf("%d", &num);
	if(num % 2 == MALE){
	    printf("男\n");
	}
	else {
	    printf("女\n");
	}
    return 0;
}
