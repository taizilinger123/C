#include <iostream>
using namespace std;
class A{
  //如果你想修改对象的成员变量,则成员变量需要修饰成mutable
  mutable int data;
  public:
  //注意一下const参数加的位置
  void show()const{
	//const 函数 不能修改对象的成员变量,只能读cout
	data=1;
	//cout<<data<<endl;
	//const函数  只能调用const函数
	//readData();
    cout<<"this is const show()"<<endl;
  }
  void readData(){
     cout<<data<<endl;
  }
  /*void show(){
    cout<<"this is show()"<<endl;
  }*/
};
int main(){
   A  a;
   //非const对象优先选择  非const函数  如果没有非const  函数则调用const函数
   a.show();
   //const对象必须初始化
   const A b=a;
   b.show();
}

/*
   root@test:/home/test/biaoc/C/C++/day04# g++ -S  const.cpp生成汇编
   root@test:/home/test/biaoc/C/C++/day04# vi const.s
   11 _ZNK1A4showEv:  有const参数的函数多了个K
   41 _ZN1A4showEv:   没有const参数的函数
*/
