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
int main(){
  /*在数据前加空间名*/
  ibm::show();
  tarena::show();
  ibm::age=51;
  ibm::show();
  tarena::age=11;
  tarena::show();
}

/*
 root@test:/home/test/biaoc/C/C++/day01# g++  namespace3.cpp 
 root@test:/home/test/biaoc/C/C++/day01# ./a.out 
 10
 */
