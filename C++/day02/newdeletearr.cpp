#include <iostream>
using namespace std;
int main(){
  int* parr=new int[5];
  parr[0]=9;
  *(parr+1)=5;
  //*(++parr)=5;
  parr[2]=2;
  parr[3]=7;
  parr[4]=0;
  for(int i=0;i<5;i++){
     cout<<parr[i]<<endl;
  }
  delete[] parr;
  parr=NULL;
}
