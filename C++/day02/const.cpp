#include <iostream>
using namespace std;
int main(){
  int a=100;
  const int *pa=&a;
  //*pa=101;
  int b=200;
  pa=&b;
  cout<<*pa<<endl;
  cout<<"-----------"<<endl;
  int* const  ra=&a;
  //ra=&b;
  *ra=1000;
  cout<<a<<endl;
}
