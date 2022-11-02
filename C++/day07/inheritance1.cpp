#include <iostream>
using namespace std;
class Person{
   string name;//string是4个自己
   int    age;
   public:
   Person(string name="",int age=0):name(name),age(age){
      
   }
   void  show(){
      cout<<"this is a  person show()"<<endl;
   }
};
class Emp:public Person{//:public Person继承写法
   double salary;//double是8个字节  
   public:
   void showemp(){
      cout<<"have salary"<<endl;
   }
};
int main(){
   cout<<sizeof(Person)<<endl;
   cout<<sizeof(Emp)<<endl;
   Emp  e;
   e.show();
   e.showemp();
}
