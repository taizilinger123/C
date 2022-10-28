#include <iostream>
using namespace std;
class Producter{
   string name;
   double price;
   int    count;
   public:
   Producter(string name="",double price=0.0,int count=0):name(name),price(price),count(count){
   
   }
   /*函数对象*/
   double operator()(string name,double price,int count){
        return price*count;
   }
   /*处理类型转换*/
   operator double (){
      return this->price*this->count;
   }
};
int main(){
	Producter p;
	cout<<p("pingguo",2.8,10)<<endl;
	cout<<p("juzi",0.6,9)<<endl;
	Producter p2("xigua",10.4,6);
	/*类型转换*/
    double price=(double)p2;
	cout<<price<<endl;
}
