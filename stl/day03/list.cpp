#include <list>
#include "print.h"
int main(void) {
  list<int> li;
  li.push_back(50);
  li.push_back(30);
  li.push_back(30);
  li.push_back(30);
  li.push_back(20);
  li.push_back(40);
  li.push_back(20);
  li.push_back(20);
  li.push_back(30);
  print(li.begin(), li.end());
  li.unique();
  print(li.begin(), li.end());
  list<int> ls;

  return 0;
}

/*
 root@test:/home/test/biaoc/C/stl/day03# g++  list.cpp 
 list.cpp:1:2: error: invalid preprocessing directive #inlcude
  #inlcude <list> 这种报错很多的解决从上往下，解决第一个就行,解决第一个下面都全部好了
    ^
	list.cpp: In function ‘int main()’:
	list.cpp:4:3: error: ‘list’ was not declared in this scope
	   list<int> li;
	      ^
		  list.cpp:4:8: error: expected primary-expression before ‘int’
		     list<int> li;
			         ^
					 list.cpp:5:3: error: ‘li’ was not declared in this scope
					    li.push_back(50);
						   ^
 */
