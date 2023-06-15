#include <iostream>
#include <fstream>
using namespace std;
int main(){
   ifstream ifs("copy.cpp");
   ofstream ofs("ccopy.cpp");
   char c;
   while(ifs.get(c)){
      ofs.put(c);
   }
   /*流出问题之后 只是拒绝io 其它操作不影响*/
   ifs.close();
   ofs.close();
}
