//模板的模板型成员类型
#include <iostream>
using namespace std;
template<typename K>
class Pair{
public:
  Pair(const K& k):m_k(k){}
  K m_k;
  template<typename V>
  class Value{
  public:
	Value(const V& v):m_v(v){}
    V m_v;
  };
};
int main(void){
    Pair<string> pair("PAI");
	Pair<string>::Value<double> value(3.14);
	cout<<pair.m_k << '=' << value.m_v <<endl;
	return 0;
}
