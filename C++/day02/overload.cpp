#include <iostream>
using namespace std;
int add(int a,int b){
	cout<<"add(int,int)"<<endl;
    return a+b;
}
double add(int a,double b){
	cout<<"add(int,double)"<<endl;
    return a+b;
}
double add(double a,int b){
	cout<<"add(double,int)"<<endl;
    return a+b;
}
int main(){
   add(1,1);
   add(1.0,1);
   add(1,1.0);
}
