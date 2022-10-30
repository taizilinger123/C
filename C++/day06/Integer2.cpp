#include <iostream>
using namespace std;
extern "C" void* malloc(size_t size);//C++调用C的
extern "C" void free(void *ptr);
class Integer{
  int data;
  int d2;
  public:
  explicit Integer(int data=0):data(data){//单参构造：如果一个类中有一个单参的构造函数则系统允许  把这个单参类型变量  转换成这个类类型, explicit不允许一个整型int转换成Integer,只在类中有效
    cout<<"Integer()"<<endl;
  }
  ~Integer(){
     cout<<"~Integer()"<<endl;
  }
  static void* operator new(size_t size){
    cout<<"mem new "<<size<<endl;
	return malloc(size);
  }
  static void operator delete(void* ptr){
       free(ptr);
  }
  /*重载()把Integer变成int*/
  operator int(){
    return data;
  }
};
void* operator new(size_t size){
    cout<<"g new "<<size<<endl;
	return malloc(size);
}
int main(){
  Integer *pi=new Integer();
  delete pi;
  //Integer ii=100;//单参构造int to Integer
  Integer ii(100);
  int iv=(int)ii;//Integer to int
  cout<<iv<<endl;
  
}
