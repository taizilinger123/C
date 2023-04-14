#include <iostream>
using namespace std;
class Animal{
   public:
   virtual void fun(){
      cout<<"这是动物的功能"<<endl;   
   }
};
class Dog:public Animal{
   public:
   void fun(){
      cout<<"看家"<<endl;
   }
   void fun2(){
      cout<<"抓坏人"<<endl;
   }
};
class Cat:public Animal{
   public:
   void fun(){
      cout<<"抓老鼠"<<endl;
   }
};
void testfun(Animal* a){
   a->fun();
}
Animal* testfun2(int a){
   if(a==1){
      return new Dog();
   }else{
      return new Cat();
   }
}
int main(){
   Dog dog;
   Cat cat;
   testfun(&dog);
   testfun(&cat);
}
