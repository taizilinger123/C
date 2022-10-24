#include <iostream>
using namespace std;
class Integer{
   int data;
   public:
   Integer(int data=0):data(data){
      
   }
   /* 负号运算符 - ! ~  */
   const Integer  operator-()const{
      return Integer(-data);
   }
   /* !运算符重载 */
   const Integer operator!()const{
      return Integer(!data);
   }
   /* ++i 前++运算符重载 变量的值和表达式的值一致 */
   Integer&   operator++(){
      ++data;
	  return *this;
   }      
   /* 后++ 用哑元分区 表达式的值和变量原来的值一致 */
   Integer   operator++(int){
      return Integer(data++);
   }      
   friend ostream&  operator<<(ostream& os, const Integer& i){
      return os<<i.data;
   }
   friend istream& operator>>(istream& is,Integer& i){
      return is>>i.data;
   }
   Integer& operator+=(const int b){
      this->data+=b;
	  return *this;
   }
};
int main(){
   Integer i;
   cout<<++i<<endl;
   cout<<i<<endl;
   cout<<i++<<endl;
   cout<<i<<endl;
   cout<<"-----------"<<endl;
   cin>>i;
   cout<<-i<<endl;
   //i+=100;
   cout<<i<<endl;
   cout<<!i<<endl;
   cout<<!!i<<endl;
}
