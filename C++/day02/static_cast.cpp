#include <iostream>
using namespace std;
int main(){
  int a=100;
  int* pa=&a;
  void *pv=pa;
  pa=static_cast<int*>(pv);
}
