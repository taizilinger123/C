/*
   第一个作业
 */
#include <stdio.h>
int main(){
	int num = 54321, num1 = 10000;
	printf("%d\n", num);
    num = num % num1;
	num1 = num1 / 10;

	printf("%d\n", num);
    num = num % num1;
	num1 = num1 / 10;

	printf("%d\n", num);
    num = num % num1;
	num1 = num1 / 10;

	printf("%d\n", num);
    num = num % num1;
	num1 = num1 / 10;

	printf("%d\n", num);
    return 0;
}
