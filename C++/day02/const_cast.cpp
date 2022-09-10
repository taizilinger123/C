#include <iostream>
using namespace std;
int main(){
  volatile const int  a=100;
  //int* pa=(int*)&a;
  int*pa=const_cast<int*>(&a);
  *pa=100001;
  cout<<a<<endl;
  /*最接近强制类型转换 */
  //reinterpret_cast<类型>(变量);
  int *pi=reinterpret_cast<int*>(0x31323334);
}
