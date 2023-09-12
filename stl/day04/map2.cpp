#include <iostream>
#include <map>
using namespace std;
int main(void) {
  map<string, int> msi;
  msi["张飞"] = 85;
  msi["赵云"] = 90;
  msi["关羽"] = 88;
  msi["刘备"] = 60;
  msi["曹操"] = 75;
  typedef map<string, int>::iterator IT;
  for(IT it = msi.begin(); it != msi.end(); ++it)
	  cout << it->first << "同学得" << it->second << "分。"<<endl;
  return 0;
}
