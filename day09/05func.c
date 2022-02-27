/*
  函数练习 
*/
#include <stdio.h>
int add() {
    return 2 + 4;
}
int read(){
    int num = 0;
	printf("请输入一个数字：");
	scanf("%d", &num);
	return num;
}
void print1(){
    printf("1\n");
} 
int main(){
	int num = 0;
	//num = add();
	num = read();
	printf("num是%d\n", num);
	print1();
    return 0;
}
