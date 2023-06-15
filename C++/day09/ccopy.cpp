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
   ifs.close();
   ofs.close();
}
