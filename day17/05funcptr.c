/*
 函数指针练习
 */
#include <stdio.h>
int add(int x, int y){
   return x + y;
}
int sub(int x, int y){
   return x - y;
}
int mul(int x, int y){
   return x * y;
}
int div(int x, int y){
   return x / y;
}
int main(){
	int x, y;
	char ch;
	printf("请输入计算公式: ");
	scanf("%d%c%d", &x, &ch, &y);
    int (*p_Func)(int, int) = NULL;
	if (ch == '+'){
	   p_Func = add;
	}
	else if (ch == '-'){
	   p_Func = sub;
	}
	else if (ch == '*'){
	   p_Func = mul;
	}
	else {
	   p_Func = div;
	}
	printf("计算结果是%d\n",p_Func(x, y));
    return 0;
}
