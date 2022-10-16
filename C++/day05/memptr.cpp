#include <iostream>
using namespace std;
class Date{
   public:
   int year;
   int month;
   int day;
   public:
   Date(int year=2022,int month=1,int day=1):year(year),month(month),day(day){
       
   }
};
int main(){
   Date  date;
   /*定义成员指针*/
   union{
       int  Date::*mptr;
	   int  *myptr;
   };
   mptr=&Date::year;
   cout<<date.*mptr<<endl;
   cout<<"mptr="<<myptr<<endl;
   mptr=&Date::month;
   cout<<date.*mptr<<endl;
   cout<<"mptr="<<myptr<<endl;

}
