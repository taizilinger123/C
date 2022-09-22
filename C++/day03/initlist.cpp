#include <iostream>
#include <string>
using namespace std;
class Emp{
   string name;
   int&    age;
   const double salary;
   public:
   /*构造函数 初始化参数列表 在构造函数的参数列表之后  构造函数实现体之前的区域 :salary(10000),age(age),name("sunyang")*/
   Emp(int& age):salary(10000),age(age),name("sunyang"){
       //salary=10000;       
	   this->name="test name";
   }
   void show(){
      cout<<name<<" "<<age<<" "<<salary<<endl;
   }
   void setName(string name){
      this->name=name;
	  cout<<"this="<<this<<endl;
   }
};
int main(){
   int age=22;
   Emp  emp(age);
   emp.show();
   emp.setName("kongka");
   cout<<"&emp="<<&emp<<endl;
   emp.show();
   Emp emp2(age);
   emp2.setName("meixi");
   cout<<"&emp2="<<&emp2<<endl;
   emp2.show();
   emp.setName("test");
}
