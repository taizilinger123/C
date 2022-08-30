#include <iostream>
using namespace std;

int main(){
    union{
	  int d;
	  char data[4];
	};
	//d=0x31323334;
	  d=0x41424344;
	/* 如果大端序 输出就是 1 2 3 4 
	   如果小端序 输出就是 4 3 2 1
	   网络序是大端序
	   int x=100; htonl(x) 
	 */
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
