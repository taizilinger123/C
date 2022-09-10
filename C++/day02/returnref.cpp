#include <iostream>
using namespace std;
int&  add(int& a,int b){
  a=a+b;
  return a;
}
int main(){
  int x=100;
  int& y=add(x,1);
  cout<<"y="<<y<<endl;
  //y=11;
  /*返回值作为左值*/
  add(x,0)=1111;
  cout<<"x="<<x<<endl;
  cout<<"y="<<y<<endl;
}
