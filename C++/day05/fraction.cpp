#include <iostream>
using namespace std;
class Fraction{
    int x;
	int y;
	public:
	Fraction(int x=0,int y=1):x(x),y(y){
	    
	}
	void show(){
	   cout<<x<<"/"<<y<<endl;
	}
};
int main(){
    Fraction  f1(1,2);
	f1.show();
	Fraction  f2(1,3);
	f2.show();
	/*设计一个函数 把两个分数相加*/ 
    
}
