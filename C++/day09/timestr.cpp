#include <cstdio>
#include <ctime>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
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
}
