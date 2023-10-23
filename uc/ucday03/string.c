#include <stdio.h>
#include <string.h>

//作为程序员，必须掌握的字符串的操作
//字符串的表示方式: char* char[] ""
int main(){
  //1 字符串赋值 -a 数组类型用strcpy()
  //b malloc内存用strcpy(),用=内存泄漏
  //c char* 类型看指向
  // = 改内存地址，strcpy()改值/地址不变
  char* s1 = "abcd";//指向只读常量区
  s1 = "1234";//行，改了地址
  //strcpy(s1,"567");//修改只读区，段错误
  char s2[5] = "abcd";//指向栈区，复制值
  //s2 = "1234";//s2是常指针，不能改地址
  strcpy(s2,"1234");//常指针可以改值
  //2 字符串的指针操作 - 字符串数组操作和
  //单字符串操作，字符串数组以NULL结束，
  //单字符串以'\0'结束
  //3 字符串的比较 - 比较相等/比较大小
  //strcmp()全部比较 /strncmp()比较前n个字符
  //4 字符串的长度和buf的size
  char buf[200] = {};
  strcpy(buf,"abc");
  printf("string length=%d\n",strlen(buf));
  printf("buf size=%d\n",sizeof(buf));
  //5 字符串的拼接
  char* s4 = "abc";
  char* s5 = "123";
  char buf2[100] = {};
  strcpy(buf2,s4);
  strcat(buf2,s5);
  printf("buf2=%s\n",buf2);
  //6 字符串和其他类型的转换(int/double)sprintf
  int i1 = 100;
  char* s6 = "2000";
  char buf3[20] = {};
  sprintf(buf3,"%d",i1);
  printf("buf3=%s\n",buf3);//int->char*
  int i2;
  sscanf(s6,"%d",&i2);
  printf("i2=%d\n",i2);//char* ->int
}
