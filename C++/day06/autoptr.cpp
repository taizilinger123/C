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
   void show(){
      cout<<"show()"<<endl;
   }
};
class autoptr{
   A*  data;
   public:
   autoptr(A* data):data(data){
      
   }
   ~autoptr(){
     delete data;
   }
   /*重载->运算符*/
   A* operator->(){
     return data;
   }
   /*重载* 运算符*/
   A& operator*(){
      return *data;
   }
};
int main(){
   A*  a=new A();
   autoptr atr(a);
   atr->show();
   atr.operator->()->show();
   (*atr).show();
}
