#include <stdio.h>
#include "mymath.h"
//int add(int,int);
int main(){
   printf("%d\n",add(1,97));
}

/*
 root@test:/home/test/biaoc/C/C++/day02/callfun# g++  -S mymath.cpp 
 root@test:/home/test/biaoc/C/C++/day02/callfun# ls
 mymath.cpp  mymath.h  mymath.s
 root@test:/home/test/biaoc/C/C++/day02/callfun# rm  -rf  mymath.s
 root@test:/home/test/biaoc/C/C++/day02/callfun# ls
 mymath.cpp  mymath.h
 root@test:/home/test/biaoc/C/C++/day02/callfun# g++ -c  mymath.cpp
 root@test:/home/test/biaoc/C/C++/day02/callfun# ls
 mymath.cpp  mymath.h  mymath.o
 root@test:/home/test/biaoc/C/C++/day02/callfun# vi callcppfun.c
 root@test:/home/test/biaoc/C/C++/day02/callfun# ls
 callcppfun.c  mymath.cpp  mymath.h  mymath.o
 root@test:/home/test/biaoc/C/C++/day02/callfun# gcc  callcppfun.c mymath.o  -lstdc++
 root@test:/home/test/biaoc/C/C++/day02/callfun# ls
 a.out  callcppfun.c  mymath.cpp  mymath.h  mymath.o
 root@test:/home/test/biaoc/C/C++/day02/callfun# ./a.out 
 98
    如果用c++实现一个函数  需要在实现中加一个extern  "C" 然后提供一个供c调用的头文件
	      如果用c实现一个函数  但需要给c++提供一个调用的头文件 这个头文件中需要加一个extern  "C"声明。
 */
