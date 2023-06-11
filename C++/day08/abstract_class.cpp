#include <iostream>
using namespace std;
class Animal{
   public:
   //纯虚函数
   virtual void run()=0;
};
//如果子类继承了抽象类 不去实现纯虚函数 则子类成为抽象类。
class Dog:public Animal{
   public:
   //以下实现了纯虚函数，空实现函数
   void run(){}
};
int main(){
   //Animal a;
   Dog dog;
}
