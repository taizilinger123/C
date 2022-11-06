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
};
class B:public A{
   public:
   int x;
   void show(){
      cout<<"B show()"<<endl;
   }
};
int main(){
   B  b;
   cout<<b.x<<endl;
   b.show();
   b.A::show();
}
