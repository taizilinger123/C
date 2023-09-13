#include <iostream>
#include <map>
using namespace std;
template<typename IT>
void print(IT begin, IT end){
  for(IT it = begin; it != end; ++it)
	  cout << it->first << "同学得" << it->second << "分。"<<endl;
}
int main(void) {
  map<string, int> msi;
  msi["zhangfei"] = 85;
  msi["zhaoyun"] = 90;
  msi["guanyu"] = 88;
  msi["liubei"] = 60;
  msi["caocao"] = 75;
  print(msi.begin(), msi.end());
  cout << "----------------"<<endl;
  typedef map<string, int>::iterator IT;
  IT it = msi.begin();
  ++it;
  msi.erase(it);
  print(msi.begin(), msi.end());
  cout << "----------------"<<endl;
  IT begin = msi.begin();
  ++begin;
  IT end = msi.end();
  --end;
  msi.erase(begin, end);
  print(msi.begin(), msi.end());
  cout << "----------------"<<endl;
  msi.erase("zhaoyun");
  print(msi.begin(), msi.end());
  return 0;
}
