#include <iostream>
using namespace std;
struct Date{
   int year;
   int month;
   int day;
   /*设置日期*/
   void setDate(int y=2013,int m=1,int d=1){
     /*成员函数中 可以直接访问成员变量*/
	 year=y;
	 month=m;
	 day=d;
   }
   /*显示函数*/
   void showDate(){
     cout<<year<<"-"<<month<<"-"<<day<<endl;
   }
};
int main(){
   cout<<sizeof(Date)<<endl;
   /*如何创建对象 */
   Date date; //在栈里创建对象
   //date.year=2013;
   date.setDate();
   date.showDate();
}
