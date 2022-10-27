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
	int& operator[](int ind){
	    if(ind>=size){
		   throw "下标越界";
		}
		return data[ind];
	}
    /*提供一个函数 放入数据*/
	Array& push_back(int d){
	    if(size+1<=maxsize){
		   data[size++]=d;
		}else{
		   throw "数组已满";
		}
		return *this;
	}
};
int main(){
    Array  a(5);
	a.push_back(100);
	a.push_back(300).push_back(200).push_back(2).push_back(3);
	/*
	 terminate called after throwing an instance of 'char const*'
	 已放弃 (核心已转储)
	 */
    try{
	   a.push_back(555);
	}catch(const char* e){
	   cout<<e<<endl;
	}
	cout<<a[1]<<endl;
	Array  b(2);
	//b=a;
	//a=a;
}
