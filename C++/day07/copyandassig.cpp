#include <iostream>
using namespace std;
//g.拷贝构造函数   和  赋值运算符的调用
class Person{
   string name;
   int*    age;//拷贝构造函数用指针
   public:
   //Person构造函数
   Person(string name="",int age=0):name(name){
      this->age=new int(age);
   }
   //Person析构函数
   ~Person(){
      if(age){
	      delete age;
	  }
   }
   //Person拷贝构造函数
   Person(const Person& p){
	  //拷贝构造防止自赋值
	  cout<<"Person(Person)"<<endl;
      name=p.name;
	  age=new int(*(p.age));
   }
   //Person的赋值运算符
   Person& operator=(const Person& p){
	  cout<<"Person ="<<endl;
      if(this==&p){return *this;}
	  name=p.name;
	  delete age;
	  //age=new int(*(p.age));
	  age=new int;
	  *age=*(p.age);
	  return *this;
   }
};
class Emp:public Person{
   int *parr;
   double salary;
   int    size;
   //堆内存分配的4个步骤:构造函数,析构函数,拷贝构造函数,赋值运算符
   //Emp的构造函数
   public:
   Emp(string name="",int age=0,double salary=0,int size=0):Person(name,age),salary(salary),size(size){
      parr=new int[size];
   }
   //Emp的析构函数,父类的析构函数不用管会自动调用
   ~Emp(){
      delete[] parr;
   }
   //Emp的拷贝构造
   /*:Person(e)把e当Person类型来看 调用Person拷贝构造*/
   Emp(const Emp& e):Person(e){
	  cout<<"Emp(Emp)"<<endl;
      salary=e.salary;
	  size=e.size;
	  parr=new int[e.size];
	  for(int i=0;i<e.size;i++){
		  parr[i]=e.parr[i];
	  }

   }
   //Emp的赋值运算符
   /*赋值运算符 和 如何调用父类的operator=*/
   Emp& operator=(const Emp& e){
      if(this!=e){
		  //Person::调用父类的operator=
		  Person::operator=(e);
		  delete[] parr;
          parr=new int[e.size];
		  for(int i=0;i<e.size;i++){
		       parr[i]=e.parr[i];
		  }
		  size=e.size;
		  salary=e.salary;
	  }
	  return *this;
   }
};
int main(){
   Emp  e;
   Emp  ee=e;
}
