#include <iostream>
using namespace std;
class Animal{
   public:
   virtual void run(){
      cout<<"run()"<<endl;
   }
};
class Fish:public Animal{
   public:
   string name;
   //构造函数
   Fish(string name="yu"):name(name){}
   public:
   void show(){
      cout<<name<<"我是一条鱼"<<endl;
   }
   void run(){
      cout<<"fish run"<<endl;
   }
};
int main(){
   //Animal *a=new Fish();
   Animal *a=new Animal();
   Fish   *f;
   //a=f;
   //强转
   f=static_cast<Fish*>(a);
   cout<<f<<endl;
   //Fish& ff=static_cast<Fish&>(*a);
   //f->show();
   f=dynamic_cast<Fish*>(a);
   cout<<"f="<<f<<endl;
   
}
