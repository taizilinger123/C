#include <iostream>
using namespace std;
class Date{
   public:
   Date(){
      cout<<"Date()"<<endl;
   }
   ~Date(){
      cout<<"~Date()"<<endl;
   }
};
class Emp{
   Date  date;
   public:
   Emp(){
      cout<<"Emp()"<<endl;
   }
   ~Emp(){
      cout<<"~Emp()"<<endl;
   }
};
#include <cstdlib>
int main(){
   Emp *emp=static_cast<Emp*>(malloc(sizeof (Emp)));
   free(emp); //malloc申请的内存必须用free释放
   Emp *emp2=new Emp();
   delete emp2;
   Emp *emp3=new Emp[3]; //数组
   delete[] emp3;  //new申请的内存必须用delete释放
}
