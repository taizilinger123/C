#include <iostream>
#include <fstream>
#include <map>
#include <cstring>
using namespace std;
class CmpStr {
public:
   bool operator() (const string& a, const string& b) const {
      return strcasecmp(a.c_str(), b.c_str()) < 0;
   }
};
int main(int argc, char* argv[]) {
   if (argc < 2) {
      cerr << "用法:" << argv[0] << "<单词文件>"<<endl;
	  return -1;
   }
   ifstream ifs (argv[1]);
   if (! ifs) {
      cout << "打开文件失败！"<< endl;
	  return -1;
   }
   string word;
   map<string, int, CmpStr> msi;
   while (ifs >> word)
     ++msi[word];
   if(! ifs.eof()) {
     cout << "读取文件失败！" << endl;
	 return -1;
   }
   ifs.close();
   for (map<string, int, CmpStr>::const_iterator it = 
	msi.begin(); it != msi.end(); ++it)
	cout << it->first << "出现" << it->second << "次" <<endl;
   return 0;
}

/*
 root@test:/home/test/biaoc/C/stl/day04# g++  words.cpp 
 root@test:/home/test/biaoc/C/stl/day04# ./a.out  words.txt 
 */
