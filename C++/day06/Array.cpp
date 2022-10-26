#include <iostream>
using namespace std;
class Array{
	/*数组的空间大小*/
    int maxsize;
	/*现有的元素数*/
	int size;
	/*真正存储数据的空间*/
	int *data;
	public:
	/*构造函数*/
	Array(int maxsize=0):maxsize(maxsize),size(0){
	    data=new int[maxsize];
	}
	/*析构函数*/
	~Array(){
	    delete[] data;
	}
	/*拷贝构造函数*/
	Array(const Array& a){
	    maxsize=a.maxsize;
		size=a.size;
		data=new int[maxsize];
		for(int i=0;i<size;i++){
		   data[i]=a.data[i];
		}
	}
	Array  operator=(const Array& a){
		/*防止自赋值*/
		if(this==&a){
		   return *this;
		}
	    maxsize=a.maxsize;
		size=a.size;
		delete[] data;
		/*释放原来的内存空间*/
		data=new int[maxsize];
		for(int i=0;i<size;i++){
		   data[i]=a.data[i];
		}
		/*返回当前对象的值*/
		return *this;
	}
	/* [] 运算符 int operator[](int ind) */

};
int main(){
    Array  a(1);
	Array  b(2);
	//b=a;
	a=a;
}
