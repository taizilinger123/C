//模板的模板型成员变量
#include <iostream>
using namespace  std;
template<typename V>
class Value{
public:
  Value(const V& v):m_v(v){}
  V m_v;
};
template<typename K, typename V>
class Pair{
public:
  Pair(const K& k, const V& v):m_k(k), m_v(v){}
  K m_k;
  Value<V> m_v;//
};
int main(void){
   Pair<string, double> pair("PAI", 3.14);
   cout<<pair.m_k << '='<<pair.m_v.m_v <<endl;
   return 0;
}
