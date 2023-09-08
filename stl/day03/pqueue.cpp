#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Prioritize {
public:
  bool operator()(int a, int b) const {
     return a > b;
  }
};
int main(void){
  priority_queue<int, vector<int>, Prioritize> qi;
  qi.push(23);
  qi.push(17);
  qi.push(29);
  qi.push(10);
  qi.push(17);
  while(! qi.empty()) {
    cout << qi.top() << ' ';
	qi.pop();
  }
  cout << endl;
  return 0;
}
