#include <iostream>
using namespace std;
class A;
void gshow(A* a);
class A{
  public:
  int data;
  public:
  A():data(10000){
    
  }
  private:
  void show(){
    gshow(this);
  }
  public:
  void gg(){
    show();
  }
  A&   addadd(){
     data++;
	 return *this;
  }
};
void gshow(A* a){
   cout<<"data="<<a->data<<endl;
}
extern "C" void _ZN1A4showEv(A* th);
int main(){
  A  a;
  a.gg();
  //a.show();
  _ZN1A4showEv(&a);
  cout<<"--------------"<<endl;
  a.addadd().addadd().addadd();
  //a.show();
}
