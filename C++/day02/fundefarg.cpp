#include <iostream>
using namespace std;
int add(int x,int y=1,int z=100){
   return x+y+z;
}
/*int add(int x,int y){
   return x+y;
}*/
int main(){
    cout<<add(1,2)<<endl;
	cout<<add(1,2,3)<<endl;
}
