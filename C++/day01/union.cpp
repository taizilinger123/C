#include <iostream>
using namespace std;

int main(){
    union{
	  int d;
	  char data[4];
	};
	d=0x31323334;
	for(int i=0;i<4;i++){
	    cout<<data[i]<<" ";
	}
	cout<<endl;
}

/*
 root@test:/home/test/biaoc/C/C++/day01# g++  union.cpp 
 root@test:/home/test/biaoc/C/C++/day01# ./a.out 
 4 3 2 1
 */
