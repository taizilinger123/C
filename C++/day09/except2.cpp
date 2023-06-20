#include <iostream>
#include <typeinfo>
using namespace std;
class A{
   public:
   /*如果一个函数不写抛出异常 则代表可能抛出任何异常*/
   virtual void show()throw(int,double){}
};
class B:public A{
   virtual void show()throw(int){
   
   }
};
int main(){
   A* a=NULL;
   cout<<typeid(a).name()<<endl;
   try{
      cout<<typeid(*a).name()<<endl;
   }catch(bad_typeid& e){
      cout<<e.what()<<endl;
   }
   //A *aa=new A();
   A *aa=new B();
   B *b=dynamic_cast<B*>(aa);//c的方式,指针方式是空指针异常
   cout<<b<<endl;
   try{
      B& bb=dynamic_cast<B&>(*aa);//c++的方式,引用是值动态类型,出bad_cast
   }catch(bad_cast& b){
      cout<<"类型转换失败"<<endl;
   }
}
