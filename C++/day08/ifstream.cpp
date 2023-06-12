#include <iostream>
#include <fstream>
using namespace std;
int main(){
   ifstream  ifs("animal.cpp");
   if(!ifs){
      cout<<"open file failed"<<endl;
   }
   char c;
   while((c=ifs.get())!=EOF){
      cout.put(c);
   }
   ifs.close();
}
