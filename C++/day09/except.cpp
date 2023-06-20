#include <iostream>
#include <stdexcept>
using namespace std;
int main(){
   try{
      int *parr=new int[1000000000];
   }catch(bad_alloc& e){
      cout<<"申请内存过大"<<endl;
	  cout<<e.what()<<endl;
   }
   string  abc("hello");
   cout<<abc[4]<<endl;
   cout<<abc[5]<<endl;
   cout<<abc.at(4)<<endl;
   try{
       cout<<abc.at(5)<<endl;//看报错出现异常的代码的地方
   }catch(out_of_range& e){
       cout<<e.what()<<endl;
   }
}
