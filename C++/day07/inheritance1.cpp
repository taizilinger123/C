#include <iostream>
using namespace std;
class Person{
  //Person*  p; //不能写成Person p;void  test(Person p)这个test函数重复调用Person把栈撑爆了要写成指针形式Person* p;下面test函数的形参就可以用了
   string name;//string是4个自己
   int    age;
   public:
   Person(string name="",int age=0):name(name),age(age){
      
   }
   void  show(){
      cout<<"this is a  person show()"<<endl;
   }
   void  test(Person p){
      
   }
};
class Student{//空的学生类大小是1
   public:
   Person  p;
};
class Emp:public Person{//:public Person继承写法
   double salary;//double是8个字节  
   public:
   void showemp(){
      cout<<"have salary"<<endl;
   }
};
int main(){
   cout<<sizeof(Student)<<endl;
   Student  stu;
   stu.p.show();
   cout<<sizeof(Person)<<endl;
   cout<<sizeof(Emp)<<endl;
   Emp  e;
   e.show();
   e.showemp();
}
