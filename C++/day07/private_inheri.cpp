#include <iostream>
using namespace std;
class A{
   private:int x;
   protected:int y;
   public:int z;
   public:A(int x=100,int y=200,int z=400){
     this->x=x;this->y=y;this->z=z;		  
   }
   /*上面写法跟下面一样*/
   //public:A(int x=100,int y=200,int z=400):x(x),y(y),z(z){}
   public:
   void showx(){
      cout<<"x="<<x<<endl;
   }
};
class B:private A{/*y z权限会变成私有的*/
   public:
   void showyz(){
	  showx();
      cout<<"y="<<y<<" "<<"z="<<z<<endl;
   }
   /*如何访问到A类的私有成员*/

   friend void fshowyz(B b);  
};
void fshowyz(B b){
   cout<<b.y<<":"<<b.z<<endl;
}
//class C:public B{/*y z权限会变成私有的*/};
int main(){
  B  b;
  fshowyz(b);
  cout<<"---------------"<<endl;
  b.showyz();
}
