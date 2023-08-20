//向模板派生
#include <iostream>
using namespace std;
template<typename K, typename V, template<typename T> class  Base>
class Value : public Base<K> {
public:
  Value(const string& k, const V& v):Base<K>(k), m_v(v){}
  V m_v;
};
template<typename K>
class Pair{
public:
  Pair(const K& k):m_k(k){}
  K m_k;
};
int main(void){
   Value<string, double, Pair> pair("PAI", 3.14);
   cout<< pair.m_k << '=' << pair.m_v <<endl;
   return 0;
}
