/*
 通用类型指针做形参练习
 */
#include <stdio.h>
void print(void *p_num, int type){
    if (type == 1){
	   printf("%c\n", *(char*)p_num); //(char*)p_num意思是转换指针为字符指针类型，*(char*)p_num意思是获取这个字符指针的值
	}
	else if (type == 2){
	   printf("%d\n", *(int*)p_num);
	}
	else {
	   printf("%g\n", *(float*)p_num);
	}
}
int main(){
  char ch = 'c';
  int num = 10;
  float fnum = 4.7f;
  print(&ch, 1);
  print(&num, 2);
  print(&fnum, 3);
  return 0;
}
