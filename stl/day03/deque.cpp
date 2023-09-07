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
   di.pop_back();
   print(di.begin(), di.end());
   //30 10 20 50 60
   di.pop_front();
   print(di.begin(), di.end());
   //10 20 50 60
   di.insert(di.begin() + 2, 70);
   print(di.begin(), di.end());
   //10 20 70 50 60
   di.erase(di.end() - 1);
   print(di.begin(), di.end());
   //10 20 70 50
   deque<int>::iterator it = find(di.begin(), di.end(), 70);
   if (it == di.end())
	   cout << "没找到!" << endl;
   else
	   cout << "找到了:" << *it << endl;
   sort(di.begin(), di.end());
   print(di.begin(), di.end());
   for(size_t i = 0; i<di.size(); ++i)
	   di[i] += 100;
   print(di.begin(), di.end());
   return 0;
}

/*
 root@test:/home/test/biaoc/C/stl/day03# g++ deque.cpp 
 root@test:/home/test/biaoc/C/stl/day03# ./a.out
 30 10 20 50 60 40 
 */
