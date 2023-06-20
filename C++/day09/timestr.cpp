#include <cstdio>
#include <ctime>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
class Date{
   int year;
   int month;
   int day;
   public:
   Date(int y=2023,int m=1,int d=1):year(y),
   month(m),day(d){ 
   }
   /*重载输出运算符，访问私有成员用friend*/
   friend ostream& operator<<(ostream& os,const Date&d){
     return os<<d.year<<'-'<<d.month<<'-'<<d.day;
   }
};
int main(){
  char timestr[100];
  time_t t=time(NULL);
  struct tm* mytm=localtime(&t);
  sprintf(timestr,
  "%04d-%02d-%02d%02d:%02d:%02dtestfile",
  mytm->tm_year+1900,mytm->tm_mon+1,
  mytm->tm_mday,mytm->tm_hour,mytm->tm_min,
  mytm->tm_sec);
  printf("%s\n",timestr);
  ostringstream ostr;
  ostr<<setfill('0')<<setw(4)<<mytm->tm_year+1900<<'-'<<
	    setw(2)<<mytm->tm_mon+1<<'-'<<
		setw(2)<<mytm->tm_mday<<"testfile";
  string cppstr=ostr.str();
  cout<<cppstr<<endl;
  istringstream istr("tarena 2013 10.23");
  string a;
  int    b;
  double c;
  istr>>a>>b>>c;
  cout<<a<<endl;
  cout<<b<<endl;
  cout<<c<<endl;
  Date date(2023,6,20);
  ostringstream odate;
  odate<<date;
  string datestr=odate.str();
  cout<<datestr<<endl;
}
