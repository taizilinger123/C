#include <iostream>
using namespace std;
template<typename T1, typename T2, typename T3>
class Trio {
public:
  Trio (void) {
      cout << "Trio<T1,T2,T3>" << endl;
  }
};
template<typename T1, typename T2>
class Trio<T1, T2, T2>{
public:
  Trio (void) {
      cout << "Trio<T1,T2,T2>"<< endl;
  }
};
template<typename T1>
class Trio<T1, T1*, T1*> {
public:
  Trio (void) {
      cout << "Trio<T1,T1*,T1*>"<< endl;
  }
};
int main(void) {
    Trio<char, short, long> t1;
	Trio<char, short, short> t2;
	Trio<char, char*, char*> t3;
	return 0;
}
