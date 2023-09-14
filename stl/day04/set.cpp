#include <iostream>
#include <set>
using namespace std;
int main(void){
	set<int> si;
	si.insert(13);
	si.insert(27);
	si.insert(19);
	si.insert(27);
	si.insert(23);
	si.insert(44);
	si.insert(13);
	for(set<int>::const_iterator it = si.begin();
	    it != si.end(); ++it)
		cout << *it << ' ';
	cout << endl;
    return 0;
}
