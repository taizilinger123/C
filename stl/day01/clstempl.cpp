#include <iostream>
#include <cstring>
using namespace std;
//类模板
template<typename T>
class Comparator {
public:
    Comparator (T x, T y): m_x(x), m_y (y) {}
	T max (void) const {
	    return  m_x > m_y ? m_x : m_y;
	}
	T min (void) const {
	    return  m_x < m_y ? m_x : m_y;
	}
private:
	T m_x;
	T m_y;
};
/*
//全类特化
template<>
class  Comparator<const char*>{
public:
  Comparator  (const char* x, const char* y):m_x(x), m_y(y){}
  const char* max (void) const {
     return strcmp(m_x, m_y) > 0 ? m_x : m_y;
  }
  const char* min (void) const {
     return strcmp(m_x, m_y) < 0 ? m_x : m_y;
  }
private:
  const char* m_x;
  const char* m_y;
};
*/
//成员特化
template<>
const char* Comparator<const char*>::max (void) const{
  return  strcmp (m_x, m_y) > 0 ? m_x : m_y;    
}
template<>
const char* Comparator<const char*>::min (void) const{
  return  strcmp (m_x, m_y) < 0 ? m_x : m_y;    
}
int main(void) {
   Comparator<int> c1 (100, 200);
   cout << c1.max () <<endl;
   cout << c1.min () <<endl;
   Comparator<string> c2 ("hello", "world");
   cout << c2.max () <<endl;
   cout << c2.min () <<endl;
   Comparator<const char*> c3 ("hello", "world");
   cout << c3.max () <<endl;
   cout << c3.min () <<endl;
   return 0;
}

/*
 root@test:/home/test/biaoc/C/stl/day01# g++  clstempl.cpp 
 root@test:/home/test/biaoc/C/stl/day01# ./a.out
 200
 100
 world
 hello
 world
 hello
 */
