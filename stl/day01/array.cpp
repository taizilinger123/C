#include <iostream>
using  namespace std;
template<typename T, size_t S>
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
  T m_array[S];
};
int main(void) {
   //Array<int, 10> a1; // OK
   //Array<int, 2 + 8> a1; // OK
   //size_t a = 2, b = 8;// ERROR
   const size_t a = 2, b = 8; // OK
   //const volatile size_t a = 2, b = 8;//带有挥发性volatile,ERROR
   Array<int, a + b> a1;
   for(size_t i = 0;i < a1.size(); ++i)
	   a1[i] = i;
   for(size_t i = 0;i < a1.size(); ++i)
	   cout << a1[i]<<' ';
   cout << endl;
   return 0;
}
//模板是在编译时候传参数，不是在运行的时候传参
