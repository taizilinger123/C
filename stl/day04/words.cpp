#include <iostream>
#include <fstream>
#include <map>
using namespace std;
int main(int argc, char* argv[]) {
   if (argc < 2) {
      cerr << "用法:" << argv[0] << "<单词文件>"<<endl;
	  return -1;
   }
   ifstream ifs (argv[1]);
   if (! ifs) {
      cout << "文件打开失败！"<< endl;
	  return -1;
   }
   string word;
   map<string, int> msi;
   while (ifs >> word)
    
   return 0;
}
