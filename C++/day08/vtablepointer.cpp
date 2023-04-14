#include<iostream>
using namespace std;
class Animal{
    int  age;
	public:
	Animal(int age=0):age(age){
	   
	}
	public:
	virtual void show(){	  
	}
	virtual void fun(){
	}
};
class Dog:public Animal{
    public:
	void fun(){
	   cout<<"看家"<<endl;
	}
};
class Cat:public Animal{
    public:
	void fun(){
	   cout<<"抓老鼠"<<endl;
	}
};
int main(){
	Cat  cat;
	Dog  dog;
	Animal *a=&dog;
	a->fun();
	/*
    cout<<sizeof(Animal)<<endl;
	Animal a(103);
	int *pi=reinterpret_cast<int*>(&a);
	cout<<*pi<<endl;
    cout<<*(pi+1)<<endl;*/
}
