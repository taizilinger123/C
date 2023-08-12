#include <iostream>
#include <cstring>
using namespace std;
//类模板
template<typename T>
class Comparator {
public:
    Comparator (T x, T y); //构造函数 
    T max (void) const;
	T min (void) const;
private:
	T m_x;
	T m_y;
};
template<typename T>
Comparator<T>::Comparator (T x, T y):m_x (x), m_y (y){}
template<typename T>
T Comparator<T>::max (void) const {
   return m_x > m_y ? m_x : m_y;
}
template<typename T>
T Comparator<T>::min (void) const {
   return m_x < m_y ? m_x : m_y;
}

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
