#include <stdio.h>
int add(int a,int b){
   return a+b;
}
int main(){
   add(1,2);
}

/*
 root@test:/home/test/biaoc/C/C++/day02# vi  overload.cpp 
 root@test:/home/test/biaoc/C/C++/day02# g++  -S  overload.cpp 
 root@test:/home/test/biaoc/C/C++/day02# ls
 a.out  overload.cpp  overload.s
 root@test:/home/test/biaoc/C/C++/day02# vi overload.s
 root@test:/home/test/biaoc/C/C++/day02# ls
 a.out  overload.cpp  overload.s
 root@test:/home/test/biaoc/C/C++/day02# vi  cfun.c
 root@test:/home/test/biaoc/C/C++/day02# gcc  cfun.c   -S
 root@test:/home/test/biaoc/C/C++/day02# ls
 a.out  cfun.c  cfun.s  overload.cpp  overload.s
 root@test:/home/test/biaoc/C/C++/day02# vi  cfun.s
 */
