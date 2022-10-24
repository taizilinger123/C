#include <iostream>
#include <iomanip>
using namespace std;
class Integer{
   int data;
   public:
   Integer(int data=0):data(data){
   
   }
   /*+ - == > */
   const Integer operator+(const Integer& i)const{/*意思const函数也可以调*/
      return Integer(data+i.data);
   }
   /* a+=b */
   Integer& operator+=(const Integer& b){/*Integer& operator这里的Integer&用引用就可以连加等于，不用,直接用Integer就是覆盖之前的值*/
      this->data+=b.data;
	  return *this;//返回当前对象的引用
   }
   /*
	1.const Integer  const作用:管他返回值不允许被覆盖,保护返回值的
	2.const Integer& i  const作用:1.在函数内部不通过i修改Integer 2.加上const可以传一个const对象进来
	3.const{} const作用:const对象来调用operator-法
	*/
   const Integer operator-(const Integer& i)const{
      return Integer(data-i.data);
   } 
   /*==*/
   bool operator==(const Integer& i){
      //return this==&i;//==按照地址判断
	  return this->data==i.data;//==按照值来判断
   }
   /* a>b */
   bool operator>(const Integer& i)const{
      return data>i.data;
   }

   friend ostream& operator<<(ostream& os, const Integer& i){//const Integer& i这里的const是输出临时变量的
       return os<<i.data;
   }
   friend istream& operator>>(istream& is, Integer& i){
       return is>>i.data;
   }
};
int main(){
   Integer a;
   cin>>a;
   cout<<a;
   Integer b;
   cin>>b;
   cout<<b;
   //(a+b)=a;
   cout<<(a+b)<<endl;
   cout<<boolalpha<<(a==b)<<endl;//输出bool型的true和false就用boolalpha,导入头文件iomanip
   cout<<boolalpha<<(a>b)<<endl;
   cout<<((a+=b)+=b)<<endl;
   cout<<a<<endl;
}
