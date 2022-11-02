#include <iostream>
using namespace std;
class A{
   private:
   int x;
   protected:
   int y;
   public:
   int z;
   public:
   A(int x=1,int y=2,int z=100):x(x),y(y),z(z){
   }
};
class B:public A{
    public:
	void show(){
	   //cout<<x<<endl;
	   cout<<y<<endl;
	}
};
int main(){
  B  b;
  cout<<b.z<<endl;
  //cout<<b.y<<endl;
  //cout<<b.x<<endl;
  b.show();
  //下面是绕过权限访问私有的和保护的数据
  int *pi=reinterpret_cast<int*>(&b);
  cout<<*pi<<endl;
  cout<<*(pi+1)<<endl;
  cout<<*(pi+2)<<endl;
}
