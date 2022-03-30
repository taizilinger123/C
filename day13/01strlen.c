/*
 mystrlen练习
 */
#include <stdio.h>
//const修饰的是哪个形参指针的值不需要改变
int mystrlen(const char *p_str){
    //第二个变量是初始变量, \0 - 第一个字符串 = 字符串的长度
    const char *p_str1 = p_str;
	//p_str1不为\0的时候
	while (*p_str1) {
	   //p_str1向后移位
	   p_str1++;
	}
	//p_str1 - p_str就是最后一个字符串\0减去第一个字符串算出字符串的个数
	return p_str1 - p_str;
}
int main(){
   //一定要保证字符串以\0结尾的,不然就会发生数组越界
   printf("长度是%d\n", mystrlen("abcde"));
   return 0;
}
