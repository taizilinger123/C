#include <iostream>
#include <map>
using namespace std;
class Integer {
public:
   Integer(int data): m_data(data) {}
   bool operator< (const Integer& i) const {
	   cout << "比较" << m_data << "和" << i.m_data << endl;
       return  m_data < i.m_data;
   }
   int m_data;
};
int main(void){
  map<Integer, string> mis;
  mis[100] = "北京";
  mis[300] = "天津";
  mis[200] = "上海";
  mis[500] = "重庆";
  mis[400] = "广州";  
  cout << "----开始查找----" << endl;
  for (map<Integer, string>::iterator it = 
		  mis.begin(); it != mis.end(); ++it)
	  cout << it->first.m_data << " - "
		  << it->second << endl;
  map<Integer, string>::iterator it = mis.find(200);
  if(it == mis.end())
	  cout << "查找失败！"<<endl;
  else
	  cout << "查找成功："<<it->first.m_data
		  << " - " << it->second <<endl;
  return 0;
}
