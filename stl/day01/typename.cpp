#include <iostream>
using namespace std;
class A{
public:
  class B {}; //嵌套依赖类型
  struct C {};
  enum D {X,Y,Z};
  typedef unsigned int UINT;
};
template<typename T>
void foo(T t){
  typename T::B b;
  typename T::C c;
  typename T::D d;
  typename T::UINT u;
}
int main(void){
  A  a;
  foo(a);
  return 0;
}
