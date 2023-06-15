#include <iostream>
using namespace std;
int main(){
  char c;
 //cin.get(c);
  c=cin.peek();
  cout<<c<<endl;
  //cin.putback(c);
  string name;
  getline(cin,name);
  cout<<name<<endl;
}
