#include <iostream>
using namespace std;
class A{
  public:
  //注意一下const参数加的位置
  void show()const{
    cout<<"this is const show()"<<endl;
  }
  void show(){
    cout<<"this is show()"<<endl;
  }
};
int main(){
   A  a;
   a.show();
   //const对象必须初始化
   const A b=a;
   b.show();
}
