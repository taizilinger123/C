#include <iostream>
#include <typeinfo>
using namespace std;
template<typename T1, typename T2>
class Dual {
public: 
   Dual (const T1& t1, const T2& t2):m_t1 (t1), m_t2(t2){}
   void print(void) const {
      cout<<"Dual<T1,T2>"<<endl; 
	  cout<<"m_t1的类型:"<<typeid(m_t1).name()<<endl;
	  cout<<"m_t1的值:"<<m_t1<<endl;
	  cout<<"m_t2的类型:"<<typeid(m_t2).name()<<endl;
	  cout<<"m_t2的值:"<<m_t2<<endl;
   }
private:
   T1  m_t1;
   T2  m_t2;
};
int main(void){
return 0;
}
