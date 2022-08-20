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
  double money=10;
  void show(){
     cout<<"tarena age is "<<age<<endl;
  }
}
using namespace ibm;
using namespace tarena;
int main(){
	cout<<money<<endl;
	ibm::show();
}
