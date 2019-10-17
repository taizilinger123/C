/*********************************************************************************
*    Filename: 01_hello.c
* Description:
*     Version: 1.0
*     Created: 2019年10月17日  20时47分01秒
*    Revision: none 
*    Compiler: gcc
*      Author: YOUR NAME (),
*     Company:
* gcc 01_hello.c
* gcc 01_hello.c -o  hello
* ./a.out
* ./hello 
**********************************************************************************/
//1、使用某个函数前，包含相应的头文件
//2、通过man手册查看man 3 printf,/usr/include/stdio.h头文件包含的所有元素
//3、头文件类似于菜单，头文件包含函数的声明，菜单列举了菜名
//4、<>通过包含系统的头文件(标准的头文件)，""包含自定义的头文件
#include <stdio.h>
//1、C语言由函数组成，有且只有一个主函数main
//2、程序运行，先从main函数运行,main函数由系统自动调用，不需要人为调用
//3、return 0,程序正常结束
int main()
{
   //这是第一个C代码
   printf("hello mike\n");

   return 0;
}
