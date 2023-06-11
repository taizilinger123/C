#include <iostream>
#include <typeinfo>
using namespace std;
class Animal{
     public:
     virtual void show(){
	    cout<<"这是动物"<<endl;
	 }
};
class Dog:public Animal{
     public:
     void show(){
	    cout<<"这是狗"<<endl;
	 }
	 void fun(){
	    cout<<"可以看家"<<endl;
	 }
};
class Cat:public Animal{
	public:
    void show(){
	    cout<<"这是猫"<<endl;
	}
	void catchMouse(){
	    cout<<"抓老鼠"<<endl;
	}
};
void  testfun(Animal* a){
   /*在这里识别传入的对象是什么具体类型
   a->show();
   if(typeid(*a)==typeid(Cat)){
       ((Cat*)a)->catchMouse();
   }else if(typeid(*a)==typeid(Dog)){
       ((Dog*)a)->fun();
   }*/
   a->show();
   //dynamic_cast强制类型转换
   if(dynamic_cast<Cat*>(a)){
      ((Cat*)a)->catchMouse();
   }else if(dynamic_cast<Dog*>(a)){
      ((Dog*)a)->fun();
   }
}
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
   cout<<"----------------"<<endl;
   Dog tdog;
   Cat tcat;
   testfun(&tdog);
   testfun(&tcat);
}
