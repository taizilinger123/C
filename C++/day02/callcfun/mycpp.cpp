#include <iostream>
using namespace std;
#include "mymath.h"
/*_Z3addii */
int main(){
    cout<<add(1,97)<<endl;
}

/*
 root@test:/home/test/biaoc/C/C++/day02/callcfun# vi mymath.c
 root@test:/home/test/biaoc/C/C++/day02/callcfun# gcc  mymath.c -c
 root@test:/home/test/biaoc/C/C++/day02/callcfun# ls
 mymath.c  mymath.o
 root@test:/home/test/biaoc/C/C++/day02/callcfun# vi mymath.h
 root@test:/home/test/biaoc/C/C++/day02/callcfun# ls
 mymath.c  mymath.h  mymath.o
 root@test:/home/test/biaoc/C/C++/day02/callcfun# vi mycpp.cpp
 root@test:/home/test/biaoc/C/C++/day02/callcfun# ls
 mycpp.cpp  mymath.c  mymath.h  mymath.o
 root@test:/home/test/biaoc/C/C++/day02/callcfun# g++ mycpp.cpp mymath.o
 root@test:/home/test/biaoc/C/C++/day02/callcfun# ls
 a.out  mycpp.cpp  mymath.c  mymath.h  mymath.o
 root@test:/home/test/biaoc/C/C++/day02/callcfun# ./a.out
 this is c function
 98
 */
