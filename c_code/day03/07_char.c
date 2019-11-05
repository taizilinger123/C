#include <stdio.h>

int  main(int argc, char *argv[])
{
  //1、内存中没有字符，只有数字
  //2、一个数字，对应的一个字符，这种规则就是ascii 
  //3、使用字符或数字给字符变量赋值是等级

  //字符: '一个字符'
  char ch = 'a';
  printf("ch1 = %c, ch =%d\n", ch, ch); 
 
  ch = 97;//以ascii赋值，和ch = 'a'等价的
  printf("ch2 = %c\n", ch);
}
