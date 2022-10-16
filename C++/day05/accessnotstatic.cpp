#include <iostream>
using namespace std;
class A{
    private:
    int data;
	public:
	A():data(1001){
	    
	}
	public:
	static void showA(A *a){
	   cout<<"data="<<a->data<<endl;
	}
};
int main(){
   A  a;
   A::showA(&a);
}
