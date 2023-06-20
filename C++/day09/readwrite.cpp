#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class Dog{
   public:
   char   name[50];
   int    age;
   public:
   Dog(const char*name,int age){
      strcpy(this->name,name);
	  this->age=age;
   }
};
int main(){
   Dog dog("xiaoqiang",2);
   ofstream  ofs("dog.dat",ios::binary);
   if(!ofs){
     perror("open file failed");
   }
   ofs.write((char*)&dog,sizeof dog);
   ofs.close();
   /*写一个程序读取dog.dat中的内容*/
   Dog  dogdog("",0);
   ifstream ifs("dog.dat");
   if(!ifs){
      perror("打开文件失败");
	  return -1;
   }
   ifs.read((char*)&dogdog,sizeof dogdog);
   cout<<dogdog.name<<":"<<dogdog.age<<endl;
   cout<<ifs.gcount()<<endl;
   ifs.close();
}
