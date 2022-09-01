#include <iostream>
using namespace std;
void test1(){
   cout<<"this test1()"<<endl;
}
inline void test2(){
    cout<<"this inline test2()"<<endl;
}
int main(){
    test1();
	test2();
}

/*
 root@test:/home/test/biaoc/C/C++/day02# vi inline.cpp
 root@test:/home/test/biaoc/C/C++/day02# g++  -S  inline.cpp 
 root@test:/home/test/biaoc/C/C++/day02# vi inline.s
 root@test:/home/test/biaoc/C/C++/day02# rm  inline.s
 root@test:/home/test/biaoc/C/C++/day02# ls
 a.out       cfun.c         fundef.h      overload.s
 callcfun    cfun.s         inline.cpp    testfundef.cpp
 callcppfun  fundefarg.cpp  overload.cpp
 root@test:/home/test/biaoc/C/C++/day02# g++ -S  inline.cpp -O2
 root@test:/home/test/biaoc/C/C++/day02# ls
 a.out       cfun.c         fundef.h    overload.cpp
 callcfun    cfun.s         inline.cpp  overload.s
 callcppfun  fundefarg.cpp  inline.s    testfundef.cpp
 root@test:/home/test/biaoc/C/C++/day02# vi  inline.s
 */
