#include <iostream>
#include <typeinfo>
using namespace std;
class Animal{
     public:
     virtual void show(){}
};
class Dog:public Animal{

};
int main(){
   int a;
   cout<<typeid(a).name()<<endl;
   cout<<typeid(int).name()<<endl;
   cout<<typeid(&a).name()<<endl;
   cout<<typeid(int*).name()<<endl;
   if(typeid(int*)==typeid(&a)){
      cout<<"类型一致"<<endl;
   }
   Animal *aa=new Animal();
   Dog* dog=new Dog();
   cout<<typeid(aa).name()<<endl;
   cout<<typeid(*aa).name()<<endl;
   cout<<typeid(dog).name()<<endl;
   cout<<typeid(*dog).name()<<endl;
   cout<<"---------------"<<endl;
   Animal *pa=new Dog();
   cout<<typeid(pa).name()<<endl;
   /*必须满足多态性 */
   cout<<typeid(*pa).name()<<endl;
}
