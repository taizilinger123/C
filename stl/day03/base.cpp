#include <iostream>
#include <stack>
using namespace std;
int main(void){
  cout<<"整数:"<<flush;
  unsigned int numb;
  cin >> numb;
  cout << "进制:" << flush;
  unsigned int base;
  cin >> base;
  stack<unsigned int> si;
  do {
     si.push (numb % base);
  }while (numb /= base);
  cout << "结果:";
  while (! si.empty()) {
      unsigned int digit = si.top();
	  if (digit < 10)
		   cout << digit;
	  else 
		   cout << char('A' + digit - 10);
	  si.pop();
  }
  cout << endl;
  return 0;
}

/*
 root@test:/home/test/biaoc/C/stl/day03# ./a.out
 整数:1234
 进制:10
 结果:1234
 root@test:/home/test/biaoc/C/stl/day03# ./a.out
 整数:255
 进制:2
 结果:11111111
 root@test:/home/test/biaoc/C/stl/day03# ./a.out
 整数:12345678
 进制:16
 结果:BC614E
 root@test:/home/test/biaoc/C/stl/day03# ./a.out
 整数:87654321
 进制:8
 结果:516277661
 root@test:/home/test/biaoc/C/stl/day03# ./a.out
 整数:78765
 进制:13
 结果:29B0B
 root@test:/home/test/biaoc/C/stl/day03# ./a.out
 整数:90
 进制:2
 结果:1011010
 在多少进制下 13*16 = 244
 (1*X + 3)*(1*X+6) = 2*X^2 + 4*X^1 + 4*X^0
 X^2 - 5*X -14 = 0
 -2或7
 最后为7

 */
