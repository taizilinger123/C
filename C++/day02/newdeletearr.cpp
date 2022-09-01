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
  /*申请100个字节 */
  char buf[100]={0};
  /*定位分配的内存不用我们释放*/
  int *pa=new(buf)int[25];
  cout<<(void*)buf<<endl;
  cout<<pa<<endl;
}
