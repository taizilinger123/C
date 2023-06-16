#include <iostream>
#include <fstream>
using namespace std;
int main(){
    char c;
	ifstream ifs("copy.cpp");
	while(1){
	   ifs.get(c);
	   if(ifs.eof()){break;}
	   cout.put(c);
	}
	ifs.close();
}
