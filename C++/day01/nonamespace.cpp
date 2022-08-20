#include <iostream>
using namespace std;
namespace {
   int data=100;
   void test(){
      cout<<data<<endl;
   }
}
int main(){
   /*只有加上::才代表调用匿名空间的数据*/
   ::test();
}
