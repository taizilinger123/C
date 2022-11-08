#include <iostream>
using namespace std;
class Animal{
   public:
   virtual void run(){
      cout<<"this is animal run"<<endl;
   }
};
class Dog:public Animal{
   public:
   void run(){
      cout<<"this is dog run"<<endl;
   }
};
class Fish:public Animal{
   public:
   void run(){
      cout<<"this is fish run"<<endl;
   }
};
int main(){
   //Animal a=*(new Dog());
   //a.run();
   Animal *a=new Dog();
   a->run();
}
