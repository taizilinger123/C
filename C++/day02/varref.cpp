#include <iostream>
using namespace std;
int main(){
   int  a=100;
   int& b=a;
   int& c=a;
   c=101;
   cout<<"a="<<a<<","<<"b="<<b<<endl;
   int d=200;
   c=d;
   d=300;
   cout<<"a="<<a<<","<<"b="<<b<<endl;
}
