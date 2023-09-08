#include <iostream>
#include <stack>
#include <vector>
using namespace std;
template<typename T, typename C>
//T元素的类型, C底层容器的类型
class my_stack {
public:
    void push(const T& t){
	   m_c.push_back(t);
	}
	void pop (void) {
	   m_c.pop_back();
	}
	T& top (void){
	   return m_c.back();
	}
	const T& top (void) const {
	   return m_c.back();
	}
	bool empty(void) const {
	   return m_c.empty();
	}
	size_t size (void) const {
	   return m_c.size();
	}
private:
	C m_c;
};
int main(void){
  my_stack<string, vector<string> > ss;
  ss.push("饭!");
  ss.push("要吃");
  ss.push("我们");
  while (! ss.empty()) {
     cout << ss.top();
	 ss.pop ();
  }
  cout << endl;
  return 0;
}

/*
 root@test:/home/test/biaoc/C/stl/day03# g++  stack.cpp 
 stack.cpp: In function ‘int main()’:
 stack.cpp:5:3: error: ‘stack’ was not declared in this scope
    stack<string, vector<string> > ss;
	   ^
)当出现满屏的报错就是using namespace std;没定义
 */
