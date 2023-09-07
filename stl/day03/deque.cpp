#include <deque>
#include <algorithm>
#include "print.h"
int main(void){
   deque<int> di;
   di.push_back(50);
   di.push_back(60);
   di.push_back(40);
   di.push_front(20);
   di.push_front(10);
   di.push_front(30);
   print(di.begin(), di.end());
   //30 10 20 50 60 40
   return 0;
}

/*
 root@test:/home/test/biaoc/C/stl/day03# g++ deque.cpp 
 root@test:/home/test/biaoc/C/stl/day03# ./a.out
 30 10 20 50 60 40 
 */
