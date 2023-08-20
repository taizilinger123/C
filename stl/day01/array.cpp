#include <iostream>
#include <typeinfo>
#include <iomanip>
using  namespace std;
template<typename T = double, size_t S = 5>
//template<typename T = double, size_t S> //错误,缺省参数必须靠右，前面带缺省参数，后面必须带缺省参数跟函数一样
class Array{
public:
  T&  operator[] (size_t i){
      return m_array[i];
  }
  const T& operator[] (size_t i) const {
      return const_cast<T&> (*this)[i];
  }
  size_t size (void) const {
      return S;
  }
private:
  T m_array[S];//int m_array[10];T=int, S=10
};
int main(void) {
   Array<int, 10> a1; // OK
   //Array<int, 2 + 8> a1; // OK
   //size_t a = 2, b = 8;// ERROR
   //const size_t a = 2, b = 8; // OK
   //const volatile size_t a = 2, b = 8;//带有挥发性volatile,ERROR
   //Array<int, a + b> a1;
   for(size_t i = 0;i < a1.size(); ++i)
	   a1[i] = i;
   for(size_t i = 0;i < a1.size(); ++i)
	   cout << a1[i]<<' ';
   cout << endl;
   Array<string> a2;
   cout<< a2.size() <<endl;
   Array<> a3;//模板不传参数<>也必须写
   cout<<a3.size()<<endl;
   cout<<typeid(a3[0]).name()<<endl;
   cout<<setfill('$')<<setw(10)<<123<<endl;//一共10个字符宽度，空白的地方填$字符
   return 0;
}
//模板是在编译时候传参数，不是在运行的时候传参
/*
 root@test:/home/test/biaoc/C/stl/day01# g++  array.cpp 
 root@test:/home/test/biaoc/C/stl/day01# ./a.out 
 0 1 2 3 4 5 6 7 8 9 
 5
 5
 d
 $$$$$$$123
 */
