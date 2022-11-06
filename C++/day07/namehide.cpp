#include <iostream>
using namespace std;
class A{
   public:
   int  x;
   public:
   //:x(x)传值x到A的构造函数中,A(int x=0)这里x=0是给x赋初值
   A(int x=0):x(x){
     
   }
   void  show(){
      cout<<"A show()"<<endl;
   }
   static void staticshow(){
      cout<<"A  staticshow()"<<endl;
   }
};
class B:public A{
   public:
   int x;
   void show(){
	  cout<<x<<endl;
	  cout<<A::x<<endl;
      cout<<"B show()"<<endl;
   }
   static void staticshow(){
	  A::staticshow();
      cout<<"B staticshow()"<<endl;
   }
};
int main(){
   B  b;
   cout<<b.x<<endl;
   b.show();
   b.A::show();
   B::staticshow();
   //b.A::staticshow();
   B::A::staticshow();
}
