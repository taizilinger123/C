#include <iostream>
using namespace std;
class A{
   public:
   void showSelf(){
      cout<<"A showSelf "<<this<<endl;
   }
};
class B{
   public:
   void show(A& a){
      cout<<"B showSelf "<<this<<endl;
	  a.showSelf();
	  cout<<"B  again "<<this<<endl;
   }
};
int main(){
   A  a;
   B  b;
   cout<<"&a="<<&a<<endl;
   cout<<"&b="<<&b<<endl;
   b.show(a);
}
