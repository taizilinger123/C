#include <iostream>
using namespace std;
class Singleton{
   private:
   Singleton(){}
   Singleton(const Singleton& sig){}
   static Singleton sig;//static成员在类外初始化
   public:
   static Singleton& getInstance(){
     return sig;
   }
};
Singleton Singleton::sig;
int main(){
   Singleton& a=Singleton::getInstance();
   Singleton& b=Singleton::getInstance();
   Singleton& c=Singleton::getInstance();
   cout<<&a<<endl;
   cout<<&b<<endl;
   cout<<&c<<endl;
   //Singleton sig;
}
