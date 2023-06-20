#include <iostream>
#include <fstream>
using namespace std;
int main(){
  ifstream ifs("seek.dat");
  if(!ifs){
    perror("open file failed");
  }
  char name[10]={0};
  ifs.read(name,7);
  cout<<name<<endl;
  ifs.seekg(1,ios::cur);
  int data;
  ifs>>data;
  cout<<data<<endl;
  ifs.seekg(2,ios::cur);
  char sal[10]={0};
  ifs.read(sal,5);
  cout<<sal<<endl;
  ifs.close();
}
