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
template<typename T1>
class Dual<T1, int> {
//class Dual<T1, int>表示T2是int类型局部特化
public: 
   Dual (const T1& t1, const int& t2):m_t1 (t1), m_t2(t2){}
   void print(void) const {
      cout<<"Dual<T1,int>"<<endl; 
	  cout<<"m_t1的类型:"<<typeid(m_t1).name()<<endl;
	  cout<<"m_t1的值:"<<m_t1<<endl;
	  cout<<"m_t2的类型:"<<typeid(m_t2).name()<<endl;
	  cout<<"m_t2的值:"<<m_t2<<endl;
   }
private:
   T1  m_t1;
   int m_t2;
};
/*与上一个局部特化版本发生歧义
template<typename T2>
class Dual<double, T2> {
//class Dual<T1, int>表示T2是int类型局部特化
public: 
   Dual (const double& t1, const T2& t2):m_t1 (t1), m_t2(t2){}
   void print(void) const {
      cout<<"Dual<double,T2>"<<endl; 
	  cout<<"m_t1的类型:"<<typeid(m_t1).name()<<endl;
	  cout<<"m_t1的值:"<<m_t1<<endl;
	  cout<<"m_t2的类型:"<<typeid(m_t2).name()<<endl;
	  cout<<"m_t2的值:"<<m_t2<<endl;
   }
private:
   double  m_t1;
   T2      m_t2;
};
*/
template<>
class Dual<int, int> {
//class Dual<int, int>表示T1T2都是int类型完全特化
public: 
   Dual (const int& t1, const int& t2):m_t1 (t1), m_t2(t2){}
   void print(void) const {
      cout<<"Dual<int,int>"<<endl; 
	  cout<<"m_t1的类型:"<<typeid(m_t1).name()<<endl;
	  cout<<"m_t1的值:"<<m_t1<<endl;
	  cout<<"m_t2的类型:"<<typeid(m_t2).name()<<endl;
cout<<"m_t2的值:"<<m_t2<<endl;
   }
private:
   int  m_t1;
   int  m_t2;
};
int main(void){
Dual<double, double> d1 (1.23, 4.56);
d1.print();
cout<<"-------------"<<endl;
Dual<double, int> d2 (7.89, 123);
d2.print();
cout<<"-------------"<<endl;
Dual<int, int> d3 (456, 789);
d3.print();
return 0;
}
//:4,18 co 18
