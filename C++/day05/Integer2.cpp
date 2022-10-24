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
   cin>>i;
   cout<<-i<<endl;
   //i+=100;
   cout<<i<<endl;
}
