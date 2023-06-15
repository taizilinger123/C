#include <iostream>
using namespace std;
int main(){
  /*0123456789 123*/
  //char data[10];
  //cin.getline(data,10);
  string data;
  getline(cin,data,'=');
  cout<<data<<endl;
  cout<<cin<<endl;
  /*clear()复位*/
  if(!cin){ 
  cin.clear();
  /*清空缓冲区*/
  cin.ignore(100,'\n');
  }
  int dat;
  cin>>dat;
  cout<<dat<<endl;
}
