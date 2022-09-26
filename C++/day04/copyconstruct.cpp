#include <iostream>
using namespace std;
class A{
	public:
	int data;
	int *parr;
    public:
	//构造函数 申请内存
	A():parr(new int[5]){
	   data=100;
	   cout<<"A()"<<endl;
	}
	//析构函数 去释放内存
	~A(){
	    delete parr;
		parr=NULL;
	}
	//拷贝构造函数
	A(const A& a){
	   /*只要提供拷贝构造系统的就失效*/
	   cout<<"copy A()"<<endl;
	   this->data=a.data;
	   /*自己去申请内存 把数据拷贝过来
		 不去申请内存 就是释放野指针*/
       parr=new int[5];
	   for(int i=0;i<5;i++){
	      *(parr+i)=a.parr[i];
	   }
	}
};
int main(){
    A  a;
	cout<<a.data<<endl;
	A  b=a;
	cout<<b.data<<endl;
}
