#include <iostream>
#include <set>
using namespace std;
int main(void) {
   cout << "第一个字符串: " << flush;
   string s;
   cin >> s;
   set<char> s1;
   for(string::iterator it = s.begin(); it != s.end(); ++it)
	   s1.insert(*it);
   cout << "第二个字符串: " << flush;
   cin >> s;
   set<char> s2;
   for(string::iterator it = s.begin(); it != s.end(); ++it)
	   s2.insert(*it);
   for (set<char>::iterator it = s2.begin();
	   it != s2.end(); ++it)
	   if (! s1.insert(*it).second)
		   cout << *it;
   cout << endl;
   return 0;
}
