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
   //注释：不是有效代码
   //1、行注释  //相应的注释
   //2、块注释  /* 相应的注释 */
   //这是第一个C代码
 
   //1、函数调用，printf功能往标准输出设备(屏幕)打印内容
   //2、\n代表换行
   //3、函数的调用必须放在{}内部
   printf("hello mike\n");

   return 0;
}


网站来了
1.C：https://github.com/TheAlgorithms/C
2.libhv：https://github.com/ithewei/libhv
3.CPlusPlusThings：https://github.com/Light-City/CPlusPlusThings
4.design-patterns-cpp：https://github.com/JakubVojvoda/design-patterns-cpp
5.tmux：https://github.com/tmux/tmux
6.netdata：https://github.com/netdata/netdata
