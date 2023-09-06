#include <iostream>
using namespace std;
int main(void){
   cout << "输入一个字符串:"<< flush;
   string s;
   cin >> s;
   string::size_type pos = 0;
   while ((pos = s.find_first_of("0123456789", 
		pos)) != string::npos)
   cout << s[pos++];
   cout << endl;
   return 0;
}

//iconv  -f  gbk  -t utf8  movies.dat > m.dat
//rm  movies.dat 
//mv  m.dat  movies.dat
