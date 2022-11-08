#include <iostream>
using namespace std;
class A{
   public:
   A(){
      cout<<"A()"<<endl;
   }
   ~A(){
      cout<<"~A()"<<endl;
   }
   void showa(){
      cout<<"showa()"<<endl;
   }
};
class B{
   public:
   B(){
      cout<<"B()"<<endl;
   }
   ~B(){
      cout<<"~B()"<<endl;
   }
   void showa(){
      cout<<"showb()"<<endl;
   }
};
class C:public B,public A{
   public:
   C(){
     cout<<"C()"<<endl;
   }
   ~C(){
     cout<<"~C()"<<endl;
   }
   void showa(){
      cout<<"showc()"<<endl;
   }
};
int main(){
  C  c;
  c.showa();
  c.A::showa();
}
