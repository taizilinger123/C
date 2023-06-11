#include <iostream>
using namespace std;
class A{
   public:
   A(){cout<<"A()"<<endl;}
   virtual ~A(){cout<<"~A()"<<endl;}
   virtual void run(){}
};
class B:public A{
   public:
   B(){cout<<"B()"<<endl;}
   ~B(){cout<<"~B()"<<endl;}
   void run(){
      cout<<"run()"<<endl;
   }
};
int main(){
   A *a=new B();
   delete a;
}
