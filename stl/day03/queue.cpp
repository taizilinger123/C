#include <iostream>
#include <queue>
#include <list>
using namespace std;
int main(void){
   queue<string, list<string> >qs;
   qs.push("我们");
   qs.push("要玩");
   qs.push("游戏");
   while (! qs.empty()) {
      cout << qs.front();
	  qs.pop();
   }
   cout << endl;
   return 0;
}
