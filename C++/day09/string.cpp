#include <iostream>
#include <string>
using namespace std;
int main(){
   string name1("hello");
   string name2("hello");
   if(name1==name2){
      cout<<"name1 equal name2"<<endl;
   }
   name1=name1+" world";
   name1+=" end";
   cout<<name1<<endl;
   cout<<name2.size()<<endl;
   cout<<name2.at(0)<<endl;
   cout<<name2[0]<<endl;
   name2=name1;
   cout<<name2<<endl;
   const char* cstr=name2.c_str();
   cout<<cstr<<endl;
}
