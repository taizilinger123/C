#include <iostream>
#include <fstream>
//容器向量
#include <vector>
//全局迭代器
#include <iterator>
using namespace std;
int main(void) {
	vector<int> v (10);
	ifstream ifs ("i.dat");
	copy(istream_iterator<int> (ifs),
	  istream_iterator<int>(), v.begin());
	ifs.close();
	for(vector<int>::iterator it = v.begin();
		 it != v.end(); ++it)
		cout << *it << ' ';
	cout << endl;
	ofstream ofs("o.dat");
	copy(v.begin(), v.end(), ostream_iterator<int> (ofs, "$#@"));
	ofs.close();
    return 0;
}

