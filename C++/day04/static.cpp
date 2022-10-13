#include <iostream>
using namespace std;
class Animal{
   /*统计动物的数量*/
   static int  count; //静态成员变量，必须在类外初始化
   /*显示动物数量的函数*/
   public:
   static void showCount(){ //static类型共享的
      cout<<"总数量是 "<<count<<endl;
	  /*设计一个静态函数 可以访问非静态成员*/
	  //cout<<age<<endl;
   }
   int  age;
   string name;
   public:
   Animal(int age=0,string name=""):age(0),name("no name"){
       count++;
	   this->age=age;
	   this->name=name;
   }
   void show(){
       cout<<"现在动物的数量="<<count<<":"
		   <<"本对象的名字"<<name<<" age is "<<
		   age<<endl;
   }
};
int Animal::count=0; //静态变量的调用方法::,静态成员变量static int count,必须在类外初始化
int main(){
   /*不通过对象 调用静态函数*/
   Animal::showCount();//静态函数的调用方法类::静态函数
   Animal  cat(2,"cat");
   cat.showCount();
   cat.show();
   Animal  cat2(3,"cat2");
   cat2.show();
   cat.show();
}

/*
 root@test:/home/test/biaoc/C/C++/day04# vi  static.cpp
 root@test:/home/test/biaoc/C/C++/day04# g++  static.cpp 
 root@test:/home/test/biaoc/C/C++/day04# ./a.out 
 现在动物的数量=1:本对象的名字cat age is 2
 现在动物的数量=2:本对象的名字cat2 age is 3
 现在动物的数量=2:本对象的名字cat age is 2
 */
