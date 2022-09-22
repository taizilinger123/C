#include "emp.h"
#include <iostream>
using namespace std;
/*::类名作用域*/
Emp::Emp():age(22),salary(1000){
   this->name="test";
}
void Emp::show(){
   cout<<name<<" "<<age<<" "<<salary<<endl;
}
void Emp::setName(string name){
   this->name=name;
}
