#include "mytime.h"
#include <iostream>
#include <iomanip>
#include <unistd.h>
using namespace std;
MyTime::MyTime(int hour,int min,int sec):hour(hour),min(min){
   this->sec=sec;
}

void MyTime::setTime(int hour,int min,int sec){
   this->hour=hour;
   this->min=min;
   this->sec=sec;
}

void MyTime::show(){
   cout<<setfill('0')<<setw(2)<<hour<<":"<<setw(2)<<min<<":"<<setw(2)<<sec<<'\r'<<flush;
}

void MyTime::dida(){
   sleep(1);
   if(++sec==60){
        sec=0;
		if(++min==60){
		   min=0;
		   if(++hour==24){
		       hour=0;
		   }
		}
   }
}

/*
 root@test:/home/test/biaoc/C/C++/day04/mytime# man 3 sleep
 root@test:/home/test/biaoc/C/C++/day04/mytime# vi mytime.cpp 
 root@test:/home/test/biaoc/C/C++/day04/mytime# g++  mytime.cpp     #没有main函数，应该用-c参数不进行链接只进行编译
 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o：在函数‘_start’中：
 (.text+0x20)：对‘main’未定义的引用
collect2: error: ld returned 1 exit status
root@test:/home/test/biaoc/C/C++/day04/mytime# g++ -c mytime.cpp
root@test:/home/test/biaoc/C/C++/day04/mytime# vi mytime.cpp 
root@test:/home/test/biaoc/C/C++/day04/mytime# ls
mytime.cpp  mytime.h  mytime.o
root@test:/home/test/biaoc/C/C++/day04/mytime# rm *.o
root@test:/home/test/biaoc/C/C++/day04/mytime# ls
mytime.cpp  mytime.h)
 */
