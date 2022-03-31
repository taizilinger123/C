/*
 mystrcat函数练习
 */
#include <stdio.h>
char *mystrcat(char *p_str, const char *p_str1){
	int pos = 0;
	int pos1 = 0;
	//找到前一个字符串中'\0'的位置
	while(p_str[pos]){
	    pos++;
	}
	//逐个把后一个字符串中有效字符拷贝到前一个字符串后面
	while(p_str1[pos1]){
	    p_str[pos] = p_str1[pos1];
		pos++;
		pos1++;
	}
	//结束前一个字符串
	p_str[pos] = 0;
	return p_str;
    /*char *p_str2 = p_str;
	const char *p_str3 = p_str1;
	while(*p_str2){
	   p_str2++;
	}
	while(*p_str3){
	   *p_str2 = *p_str3;
	   p_str2++;
	   p_str3++;
	}
	*p_str2 = 0;
	return p_str;*/
}
int main(){
  char buf[10] = "abc";
  printf("合并结果是%s\n", mystrcat(buf, "xyz"));
  return 0;
}
