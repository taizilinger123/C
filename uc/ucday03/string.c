#include <stdio.h>
#include <string.h>

//作为程序员，必须掌握的字符串的操作
//字符串的表示方式: char* char[] ""
int main(){
//1 字符串赋值
// = 改内存地址，strcpy()改值/地址不变
  char* s1 = "abcd";//指向只读常量区
  s1 = "1234";//行，改了地址
  //strcpy(s1,"567");//修改只读区，段错误
  char s2[5] = "abcd";//指向栈区，复制值
  //s2 = "1234";//s2是常指针，不能改地址
  strcpy(s2,"1234");//常指针可以改值

}
