#include <iostream>
using namespace std;
class A{
    public:
	A(){
	  cout<<"A()"<<endl;
	}
	A(const A& a){
	    cout<<"copy A(A)"<<endl;
	}
};
A&  testA(A& a){
   return a;
}
A   testAA(){
   /*编译器优化 只调用一次构造*/
   /*A  a;
   return a;*/
   return A();//创建临时变量跟上面2行一样
}
int main(){
   /*A  a;
   testA(a);*/
   testAA();
}
