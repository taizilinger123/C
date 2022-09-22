#include "emp.h"
int main(){
   Emp emp;
   emp.show();
   emp.setName("zhunbei  xiake");
   emp.show();
}

/*
 root@test:/home/test/biaoc/C/C++/day03/emp# ls
 emp.cpp  emp.h  testemp.cpp
 root@test:/home/test/biaoc/C/C++/day03/emp# g++  testemp.cpp emp.cpp 
 root@test:/home/test/biaoc/C/C++/day03/emp# ls
 a.out  emp.cpp  emp.h  testemp.cpp
 root@test:/home/test/biaoc/C/C++/day03/emp# ./a.out 
 test 22 1000
 zhunbei  xiake 22 1000
 root@test:/home/test/biaoc/C/C++/day03/emp# g++  *.cpp
 root@test:/home/test/biaoc/C/C++/day03/emp# ./a.out 
 test 22 1000
 zhunbei  xiake 22 1000
 */
