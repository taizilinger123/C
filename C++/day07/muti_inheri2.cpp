#include <iostream>
using namespace std;
class Phone{
    double price;
	public:
	Phone(double price=0):price(price){
	   cout<<"Phone()"<<endl;
	}
	~Phone(){
	   cout<<"~Phone()"<<endl;
	}
	double getPrice(){
	   return price;
	}
};
class Camera{
    double price;
	public:
	Camera(double price=0):price(price){
	   cout<<"Camera()"<<endl;
	}
	~Camera(){
	   cout<<"~Camera()"<<endl;
	}
	double getPrice(){
	   return price;
	}
};
class Mp3{
    double price;
	public:
	Mp3(double price=0):price(price){
	   cout<<"Mp3()"<<endl;
	}
	~Mp3(){
	   cout<<"~Mp3()"<<endl;
	}
	double getPrice(){
	   return price;
	}
};
class IPhone:public Mp3,public Camera,public Phone{
    //double price;
	public:
	IPhone(double m=0,double c=0,double p=0):Phone(p),Mp3(m),Camera(c){
	   cout<<"IPhone()"<<endl;
	}
	~IPhone(){
	   cout<<"~IPhone()"<<endl;
	}
	double getPrice(){
	   //return price;
	   return Mp3::getPrice()+Camera::getPrice()+Phone::getPrice();
	}
};
int main(){
   IPhone  iphone(50,2000,500);
   cout<<iphone.getPrice()<<endl;
}
