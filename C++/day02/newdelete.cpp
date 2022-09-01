#include <iostream>
using namespace std;
int main(){
  int *pi=new int(99);
  cout<<"*pi="<<*pi<<endl;
  delete pi;
  pi=NULL;
  //cout<<"*pi="<<*pi<<endl;
}
/*
 root@test:/home/test/biaoc/C/C++/day02# ./a.out 
 *pi=99
 段错误 (核心已转储))
 */
