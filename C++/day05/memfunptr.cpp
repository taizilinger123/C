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
   void  showYear(){
       cout<<year<<endl;
   }
   void  showMonth(){
       cout<<month<<endl;
   }
};
int main(){
	/*成员函数指针定义*/
	void (Date::*funptr)();
	funptr=&Date::showYear;
	/*创建对象使用成员函数指针*/
	Date date;
	(date.*funptr)();
	funptr=&Date::showMonth;
	(date.*funptr)();
}
