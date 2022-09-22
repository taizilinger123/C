#include <iostream>
#include <string>
using namespace std;
class Emp{
   string name;
   int    age;
   const double salary;
   public:
   Emp():salary(10000),age(22),name("sunyang"){
       //salary=10000;       
   }
   void show(){
      cout<<name<<" "<<age<<" "<<salary<<endl;
   }
};
int main(){
   Emp  emp;
   emp.show();
}
