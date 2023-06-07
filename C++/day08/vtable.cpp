#include <iostream>
using namespace std;
class A{
   int data;
	public:
    A(int data):data(data){
	//构造函数
	}
	public:
	//两个虚函数，虚函数会把函数地址放到虚函数表中
	virtual  void foo1(int a){
	   cout<<"foo1"<<a<<endl;
	}
	virtual  void foo2(int){
	   //(int)这个是亚元
	   cout<<"foo2"<<data<<endl;
	}
};
//typedef类型定义
typedef void (*VFUN) (A* a,int);
//VFUN=void (*)(A* a,int);
//这个意思是定义VFUN为void (*)(A* a,int)函数的别名
typedef VFUN* VTABLE;
//这个意思是定义VFUN*为VTABLE
//VFUN*的意思是*VFUN指针的指针
int main(){
    A a(99);
    VTABLE vt=*((VTABLE*)&a);
	/*直接使用虚函数表中的地址进行调用*/
	vt[0](&a,10001);
	vt[1](&a,10);
}
