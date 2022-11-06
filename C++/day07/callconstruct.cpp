#include <iostream>
using namespace std;
class A{
   int data;
   public:
   A(){
      cout<<"A()"<<endl;
   }
   A(int a):data(a){
      cout<<"A(int)"<<endl;
   }
   ~A(){
      cout<<"~A()"<<endl;
   }
};
class B:public A{
    public:
    B():A(100){
	   cout<<"B()"<<endl;
	}
	~B(){
	   cout<<"~B()"<<endl;
	}
};
class C:public B{
    public:
	C(){
	   cout<<"C()"<<endl;  
	}
	~C(){
	   cout<<"~C()"<<endl;
	}
};
int main(){
   //B  b;
     C  c;
}
