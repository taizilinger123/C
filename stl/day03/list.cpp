#include <list>
#include <algorithm>
#include "print.h"
//比较器,比较a,b的大小a>b的话大的在前面倒序排列
class Greater {
public:
  bool operator()(int a, int b) const {
     return a > b;
  }
};
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
  ls.push_back(100);
  ls.push_back(200);
  ls.push_back(300);
  ls.push_back(400);
  ls.push_back(500);
  list<int>::iterator pos = li.begin();
  ++++++pos;
  /*
  li.splice(pos, ls);
  list<int>::iterator del = ls.begin();
  ++del;
  li.splice(pos, ls, del);
  */
  list<int>::iterator begin = ls.begin();
  begin++; // ->200
  list<int>::iterator end = ls.end();
  ----end; // ->400
  li.splice(pos, ls, begin, end);
  cout << "ls: ";
  print(ls.begin(), ls.end());
  cout << "li: ";
  print(li.begin(), li.end());
  list<int> l1, l2;
  l1.push_back(23);
  l1.push_back(58);
  l1.push_back(72);
  l1.sort(Greater());
  l2.push_back(22);
  l2.push_back(23);
  l2.push_back(49);
  l2.push_back(77);
  l2.sort(Greater());
  l1.merge(l2, Greater());
  /*
l2: 
l1: 77 72 58 49 23 23 22  比较器倒序排列
   */
  cout << "l2: ";
  print(l2.begin(), l2.end());
  cout << "l1: ";
  print(l1.begin(), l1.end());
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
