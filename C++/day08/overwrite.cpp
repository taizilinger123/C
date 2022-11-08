#include <iostream>
using namespace std;
/*
3.虚函数在子类中覆盖掉父类的实现时  必须遵守函数重写的规则(overwrite)
函数名必须相同
参数列表必须相同
返回值必须相同
访问权限没有限制
*/
class Animal{
   public:
   virtual void show(){
      cout<<"this is animal show"<<endl;
   }
};
class Dog:public Animal{
   public:
   //重写必须是虚函数，否则就是名字隐藏
   //int show(){
   void show(){
      cout<<"this is dog show"<<endl;
   }
};
int main(){
  Animal *a=new Dog();
  a->show();
  Dog dog;
  dog.show();
}
