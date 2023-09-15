#include <iostream>
#include <map>
using namespace std;
int main(void) {
  multimap<char, int> mmap;
  mmap.insert(make_pair('B', 1000));
  mmap.insert(make_pair('A', 2000));
  mmap.insert(make_pair('C', 3000));
  mmap.insert(make_pair('A', 4000));
  mmap.insert(make_pair('C', 5000));
  mmap.insert(make_pair('B', 6000));
  typedef multimap<char, int>::const_iterator CIT;
  for(CIT it = mmap.begin(); it != mmap.end(); ++it)
	  cout << it->first << " : " << it->second << endl;
  cout << "----------" << endl;
  CIT it = mmap.find('B');
  cout << it->first << " : " << it->second <<endl;
  cout << "----------" << endl;
  CIT lower = mmap.lower_bound('B');
  CIT upper = mmap.upper_bound('B');
  for (CIT it = lower; it != upper; ++it)
	 cout << it->first << ":" << it->second << endl;
  cout << "----------" << endl;
  pair<CIT, CIT> range = mmap.equal_range('B');
  for (CIT it = range.first; it != range.second; ++it)
	 cout << it->first << ":" << it->second << endl;
  return 0;
}
