#include <iostream>
#include "mytime.h"
using namespace std;
int main(){
  //MyTime mytime(10,18,50);
  /*在mytime.h头文件中加入以下的参数默认值
	MyTime(int hour=0,int min=0,int sec=0);
	void setTime(int hour=0,int min=0,int sec=0);
  */
  MyTime mytime;
  while(1){
  mytime.show();
  mytime.dida();
  }
}

/*
 root@test:/home/test/biaoc/C/C++/day04/mytime# ls
 mytime.cpp  mytime.h
 root@test:/home/test/biaoc/C/C++/day04/mytime# vi  testmytime.cpp
 root@test:/home/test/biaoc/C/C++/day04/mytime# g++ testmytime.cpp mytime.cpp
 root@test:/home/test/biaoc/C/C++/day04/mytime# ls
 a.out  mytime.cpp  mytime.h  testmytime.cpp
 root@test:/home/test/biaoc/C/C++/day04/mytime# ./a.out
 */
