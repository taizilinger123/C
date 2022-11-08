#include <iostream>
using namespace std;
class Product{
    double price;
	public:
	double getPrice(){
	   return price;
	}
	//方便子类访问要搞个构造函数
	Product(double price=0):price(price){}
};
class Phone:virtual public Product{
	public:
	Phone(double price=0):Product(price){
	   cout<<"Phone()"<<endl;
	}
	~Phone(){
	   cout<<"~Phone()"<<endl;
	}
	void phone(){
	   cout<<"打电话"<<endl;
	}
};
class Camera:virtual public Product{
	public:
	Camera(double price=0):Product(price){
	   cout<<"Camera()"<<endl;
	}
	~Camera(){
	   cout<<"~Camera()"<<endl;
	}
	void camera(){
	   cout<<"录制视频"<<endl;
	}
};
class Mp3:virtual public Product{
	public:
	Mp3(double price=0):Product(price){
	   cout<<"Mp3()"<<endl;
	}
	~Mp3(){
	   cout<<"~Mp3()"<<endl;
	}
	void mp3(){
	   cout<<"播放音乐"<<endl;
	}
};
class IPhone:public Mp3,public Camera,public Phone{
    //double price;
	public:
	IPhone(double m=0,double c=0,double p=0):Product(m+c+p){
	   cout<<"IPhone()"<<endl;
	}
	~IPhone(){
	   cout<<"~IPhone()"<<endl;
	}
	/*double getPrice(){
	   //return price;
	   return Mp3::getPrice()+Camera::getPrice()+Phone::getPrice();
	}*/
};
int main(){
   IPhone  iphone(50,2000,500);
   cout<<iphone.getPrice()<<endl;
   iphone.phone();
   iphone.mp3();
   Camera  ca(1999);
   cout<<ca.getPrice()<<endl;
   ca.camera();
}
