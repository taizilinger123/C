#include <iostream>
#include <cstdlib>
using namespace std;
class Date{
   int year;
   int month;
   int day;
   /*设置日期*/
   public:
   void setDate(int y=2013,int m=1,int d=1){
     /*成员函数中 可以直接访问成员变量*/
	 year=y;
	 month=m;
	 day=d;
   }
   /*显示函数*/
   public:
   void showDate(){
     cout<<year<<"-"<<month<<"-"<<day<<endl;
   }
};
int main(){
   cout<<sizeof(Date)<<endl;
   /*如何创建对象 */
   Date date; //在栈里创建对象,生命期短
   //date.year=2013;
   date.setDate();
   date.showDate();
   date.setDate(2013,11,11);
   date.showDate();
   /*在堆中创建对象,生命期长*/
   Date *date2=new Date;
   date2->setDate();
   date2->showDate();
   delete date2;
   date2=NULL;
   /*使用malloc申请一个Date类型的对象空间
	 给这个空间设置值 显示这个对象的数据*/
   Date* date3=static_cast<Date*>(malloc(sizeof(Date)));
   //malloc返回的是void*
   date3->setDate(2008,8,8);
   date3->showDate();
}
