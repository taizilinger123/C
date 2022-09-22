#include <iostream>
using namespace std;
class A{
   public:
   /*构造函数跟类名一样的名字*/
   A(){
      cout<<"A()"<<endl;
   }
};
class MyTime{
   int hour;
   int sec;
   int min;
   A   a;
   public:
   MyTime(){
     cout<<"this is construct MyTime()"<<endl;
   }
   MyTime(int h,int s=0,int m=0){
	  cout<<"this is MyTime(int,int=0,int=0)"<<endl;
      hour=h;
	  sec=s;
	  min=m;
   }
   void show(){
      cout<<hour<<":"<<sec<<":"<<min<<endl;
   }
};
int main(){
   /*如果构造函数中没有参数 则栈中创建对象 不能带小括号 否则将翻译成函数声明 */
   //MyTime  mytime();
   MyTime   mytime;
   mytime.show();
   MyTime   mytime2(2013);
   //MyTime  *mt=new MyTime();
   /*使用new选择构造函数创建对象*/
   MyTime *myy=new MyTime(2013,11,10);
}
