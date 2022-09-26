#include <iostream>
using namespace std;
class A{
	public:
	int data;
    public:
	//构造函数
	A(){
	   data=100;
	   cout<<"A()"<<endl;
	}
	//拷贝构造函数
	A(const A& a){
	   /*只要提供拷贝构造系统的就失效*/
	   cout<<"copy A()"<<endl;
	   this->data=a.data;
	}
};
int main(){
    A  a;
	cout<<a.data<<endl;
	A  b=a;
	cout<<b.data<<endl;
}
