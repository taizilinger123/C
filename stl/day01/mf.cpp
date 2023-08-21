//模板的模板型成员函数
#include <iostream>
using namespace std;
template<typename K>
class Pair{
public:
  Pair(const K& k):m_k(k){}
  /*
  template<typename V>
  void print(const V& v){
     cout<<m_k<<'='<<v<<endl;
  }
  */
  template<typename V>
  void print(const V& v);
  K m_k;
};
template<typename K>
   template<typename V>
void Pair<K>::print(const V& v){
   cout<< m_k << '=' << v << endl;
}
int main(void){
  Pair<string> pair("PAI");
  pair.print<double>(3.14);
  return 0;
}
