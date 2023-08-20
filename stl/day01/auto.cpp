#include <iostream>
#include <memory>
using namespace std;
class A {
public:
  A (void) {
     cout <<"A构造"<<endl;
  }
  ~A (void) {
     cout <<"A析构"<<endl;
  }
};
int main(void){
	//A* pa = new A;
    //auto_ptr<A> pa (new A);//智能指针
    auto_ptr<A> pa (new A[1]);//智能指针局部变量pa不能跟数组[1];
	return 0;
}
