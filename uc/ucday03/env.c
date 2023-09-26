#include <stdio.h>
#include <string.h>

int main(){
  extern char** environ;//全局变量环境表首地址
  char** p = environ;//不改变environ 改变p
  //练习：打印 p中所有的字符串的值,字符串数组中遍历
  while(*p/*!=NULL*/){
     printf("%s\n", *p);
	 p++;//p = p+1; p每次移动4个字节(一个指针)
  }
  p = environ;//重回首地址
  char value[100] = {};
  //练习：找到LANG的值，并存入value中
  //提示：strncmp()比较前n个字符，字符串数组中查找
  while(*p){
    if(!strncmp(*p,"LANG=",5)){
	//strncmp(*p,"LANG=",5) == 0 可以写成!strncmp(*p,"LANG=",5)，这里5的意思是LANG=是5个字符
	  strcpy(value,*p+5);//先*p后 + 5,*p+5的意思是取LANG=这个值，然后拷贝到value里面
	  break;
	}
	p++;
  }  
  printf("value=%s\n",value);
}
