#include <iostream>
using namespace std;
int main(){
   const int& ca=100;
   int b=200;
   int& rb=b;
   const int& crb=b;
   cout<<crb<<endl;
   rb=300;
   cout<<crb<<endl;
}
