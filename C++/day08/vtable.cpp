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
/*typedef void (*VFUN) (A* a,int);*/
typedef void (VFUN)(A* a,int);
//VFUN=void (*)(A* a,int);
//这个意思是定义VFUN为void (*)(A* a,int)函数的别名
//typedef VFUN* VTABLE;
typedef VFUN** VTABLE;
//这个意思是定义VFUN*为VTABLE
//VFUN*的意思是*VFUN指针的指针
//VTABLE是VFUN的数组，这个数组装了一个一个VFUN的元素, VFUN*定义出VTABLE来, int*表达int的数组
int main(){
    A a(99);
    VTABLE vt=*((VTABLE*)&a);
	//VTABLE vt这个是表示VTABLE的对象是vt,怎么取得A a(99)这个对象的虚函数表呢？
	//&a的意思是取了这个对象a的前4个字节，把这个前4个字节的值看作VTABLE*,把VTABLE*的值拿出来就要前面加*
	/*直接使用虚函数表中的地址进行调用*/
	vt[0](&a,10001);
	vt[1](&a,10);
}
