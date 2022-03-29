/*
 字符串练习
 */
#include <stdio.h>
#include <string.h>
int main(){
  char str[20] = "abc";
  char *p_str = NULL;
  printf("字符串长度是%d\n", strlen("abcdef"));
  p_str = strcat(str, "def");
  printf("str是%p,p_str是%p\n", str, p_str);
  printf("合并结果是%s\n", p_str);
  printf("比较结果是%d\n", strcmp("abc","abd"));
  printf("比较结果是%d\n", strncmp("abc","abd", 2));
  p_str = strcpy(str, "xyz");
  printf("str是%p,p_str是%p\n", str, p_str);
  printf("拷贝后字符串是%s\n", p_str);
  return 0;
}
