#include <iostream>
#include <cstdio>
#include <iomanip>
#include <unistd.h>
//man 3 sleep
//man 5 sleep
using namespace std;
class MyTime{
    int hour;
	int min;
	int sec;
	public:
	/*设置时间*/
	void setMyTime(int h=0,int m=0,int s=0){
	   hour=h;
	   min=m;
	   sec=s;
	}
	/*显示时间*/
	void showMyTime(){
	   /*printf("%02d:%02d:%02d\r",hour,min,sec);
	   fflush(stdout);*/
	   cout<<setfill('0')<<setw(2)<<hour<<":"<<
		     setw(2)<<min<<":"<<setw(2)<<sec<<'\r'<<flush;
	}
	/*调用一次 时间向前走一秒*/
    void dida(){
	   sleep(1);
	   if(++sec==60){
	     sec=0;
		 if(++min==60){
		   min=0;
		   if(++hour==24){
		      hour=0;
		   }
		 }
	   }
	}
};
int main(){
   int  h=14;
   int  m=33;
   int  s=8;
   printf("%02d:%02d:%02d\n",h,m,s);
   cout<<setw(2)<<setfill('0')<<h<<":"<<
	     setw(2)<<m<<":"<<setw(2)<<s<<endl;
   MyTime  mytime;
   mytime.setMyTime(h,m,s);
   mytime.showMyTime();
   while(1){
       mytime.dida();
       mytime.showMyTime();
   }
}
