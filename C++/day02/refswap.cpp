#include <iostream>
using namespace std;
void swap(int& a,int& b){
     a=a^b;
	 b=a^b;
	 a=a^b;
}
int main(){
   int x=10;
   int y=20;
   swap(x,y);
   cout<<x<<endl;
   cout<<y<<endl;
}
