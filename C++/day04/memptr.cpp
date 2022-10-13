#include <iostream>
using namespace std;
struct Date{
   int year;
   int month;
   int day;
   public:
   Date(int year=2022,int month=1,int day=1):year(year),month(month),day(day){
      
   }
};
int main(){
  /*定义成员指针*/
  int Date::* mptr;
  /*赋值*/
  mptr=&Date::year;  
  cout<<"mptr="<<mptr<<endl;
  Date  date;
  /*通过对象 访问成员指针对应的内容*/
  cout<<date.*mptr<<endl;
  mptr=&Date::month;
  cout<<"mptr="<<mptr<<endl;
  cout<<date.*mptr<<endl;
}
