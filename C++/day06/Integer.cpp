#include <iostream>
using namespace std;
class Integer{
  int data;
  public:
  Integer(int data=0):data(data){}
  friend ostream& operator<<(ostream& os,const Integer& i){
     cout<<i.data;
	 return os;
  }
  friend istream& operator>>(istream& is,Integer& i){
     return is>>i.data;
  }
  friend Integer& operator--(Integer& i);
  friend Integer  operator--(Integer& i,int);
};
/* 全局形式写一个前-- 后-- */
/*前-- 全局形式*/
Integer&  operator--(Integer& i){
    i.data--;
	return i;
}
/*后-- 全局形式 */
Integer  operator--(Integer& i,int){
	return Integer(i.data--);
}


int main(){
  Integer i;
  cin>>i; //10
  cout<<--i<<endl;//9
  cout<<i<<endl;//9
  cout<<i--<<endl;//9
  cout<<i<<endl;//8
}

