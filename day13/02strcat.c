/*
 mystrcat函数练习
 */
#include <stdio.h>
char *mystrcat(char *p_str, const char *p_str1){
    char *p_str2 = p_str;
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
	return p_str;
}
int main(){
  char buf[10] = "abc";
  printf("合并结果是%s\n", mystrcat(buf, "xyz"));
  return 0;
}
