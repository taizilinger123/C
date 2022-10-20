#include <iostream>
using namespace std;
class Fraction{
    int x;
	int y;
	public:
	Fraction(int x=0,int y=1):x(x),y(y){
	
	}
	/*friend 就是能访问类私有成员的全局函数*/
	friend ostream& operator<<(ostream& os,const Fraction& f);//友元，这里用友元的目的是为了访问类Fraction内的私有成员x,y,友元也是全局函数的一种,必须在类内使用友元,const也是在类内使用的

};
//ostream& operator这里防止拷贝用引用,为啥用const,这里是防止不止是const函数调用所以一般都用const函数
ostream& operator<<(ostream& os,const Fraction& f){
     return  os<<f.x<<"/"<<f.y;    
}
int main(){
	Fraction  f(1,3);
	cout<<f;//cout.operator<<(Fraction f)
}
