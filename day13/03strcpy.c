/*
 mystrcpy练习
 */
#include <stdio.h>
//因为返回值是字符串指针，所以这里的函数用字符串指针函数
//后一个指针字符串对应的值不会被改变在拷贝过程中
char *mystrcpy(char *p_str, const char *p_str1){
	//下面2个字符串的参数是为了不修改原来参数的值
    char *p_str2 = p_str;
	const char *p_str3 = p_str1;
	//逐个把后一个字符串中有效字符拷贝到前一个字符串中
	while(*p_str3){
	   *p_str2 = *p_str3;
	   p_str2++;
	   p_str3++;
	}
	//把前一个字符串结束
	*p_str2 = 0;
    return p_str;
}
int main(){
  char buf[10] = {};
  printf("拷贝的结果是%s\n", mystrcpy(buf, "abcdef"));
  return 0;
}
