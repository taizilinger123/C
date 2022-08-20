#include <iostream>
using namespace std;
namespace ibm{
   int age=50;
   void show(){
      cout<<"ibm age is "<<age<<endl;
   }
}

namespace tarena{
  int age=12;
  void show();
}
namespace tarena{
  double money;
  void show(){
     cout<<"tarena age is "<<age<<endl;
  }
}
//using ibm::age;
//using tarena::age;
using ibm::show;
using tarena::show;
int main(){
	//cout<<age<<endl;
	ibm::show();
	cout<<tarena::age<<endl;
}
