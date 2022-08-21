#include <iostream>
using namespace std;
struct Date{
  /*封装数据*/
  int year;
  int month;
  int day;
  /*封装代码*/
  void showDate(){
     cout<<year<<"-"<<month<<"-"<<day<<endl; 
  }
};
void showDate(Date date){
    cout<<date.year<<"-"<<date.month<<"-"<<date.day<<endl;     
}
int main(){
	Date date;
	cout<<sizeof date<<endl;
	Date date2={2013,11,5};
	showDate(date2);
	cout<<date2.year<<endl;
	/*调用成员函数showDate*/
	date2.showDate();
}
