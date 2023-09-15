#include <iostream>
#include <set>
using namespace std;
class A {
public:
  A (char c, int i = 0) : m_c (c), m_i (i) {}
  bool operator< (const A& that) const {
     return m_c < that.m_c;
  }
  char m_c;
  int m_i;
};
int main(void) {
  multiset<A> mset;
  mset.insert(A('B', 1000));
  mset.insert(A('A', 2000));
  mset.insert(A('C', 3000));
  mset.insert(A('A', 4000));
  mset.insert(A('C', 5000));
  mset.insert(A('B', 6000));
  typedef multiset<A>::const_iterator CIT;
  for(CIT it = mset.begin(); it != mset.end(); ++it)
	  cout << it->m_c << " : " << it->m_i << endl;
  cout << "----------" << endl;
  CIT it = mset.find(A('B'));
  cout << it->m_c << " : " << it->m_i <<endl;
  cout << "----------" << endl;
  CIT lower = mset.lower_bound(A('B'));
  CIT upper = mset.upper_bound(A('B'));
  for (CIT it = lower; it != upper; ++it)
	 cout << it->m_c << ":" << it->m_i << endl;
  cout << "----------" << endl;
  pair<CIT, CIT> range = mset.equal_range(A('B'));
  for (CIT it = range.first; it != range.second; ++it)
	 cout << it->m_c << ":" << it->m_i << endl;
  return 0;
}
