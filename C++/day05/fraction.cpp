#include <iostream>
using namespace std;
class Fraction{
	public:
    int x;
	int y;
	public:
	Fraction(int x=0,int y=1):x(x),y(y){
	    
	}
	void show(){
	   cout<<x<<"/"<<y<<endl;
	}
	/*成员函数 两个分数相加*/
	//a/b+x/y=(a*y+b*x)/b*y
	//令a=f.x,b=f.y
	//temp.x=this->x*f.y+this->y*f.x=x*f.y+y*f.x=x*b+y*a;
	//temp.y=this->y*f.y=y*f.y=y*b;
    Fraction add(const Fraction& f/*这是引用用的const*/){
        Fraction temp;
		temp.x=this->x*f.y+this->y*f.x;//a=f.x  b=f.y,这里这么写的意思是因为前面有show函数x/y,这里就用temp.x代替x,temp.y代替y 
		temp.y=this->y*f.y;
		return temp;
	}

    Fraction operator+(const Fraction& f){
        Fraction temp;
		cout<<"mem operator+"<<endl;
		temp.x=this->x*f.y+this->y*f.x;
		temp.y=this->y*f.y;
		return temp;
	}
};
/*在全局区设计一个运算符函数 */
Fraction  operator+(const Fraction& f1, const Fraction& f2){
   	return Fraction(f1.x*f2.y+f1.y*f2.x, f1.y*f2.y);	
}
int main(){
    Fraction  f1(1,2);
	f1.show();
	Fraction  f2(1,3);
	f2.show();
	/*设计一个函数 把两个分数相加*/ 
    Fraction t=f1.add(f2);
	t.show();
	//全局和成员优先选成员
    Fraction tt=f1+f2;
	tt.show();
	//Fraction ttt=f1.operator+(f2);
	Fraction  ttt=operator+(f1,f2);
	ttt.show();
}
