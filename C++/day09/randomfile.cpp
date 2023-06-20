#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int main(){
   fstream iofs("random.dat",ios::in|ios::out);
   if(!iofs){
      perror("open file failed");
   }
   cout<<iofs.tellg()<<endl;
   cout<<iofs.tellp()<<endl;
   char name[10]="hello";
   iofs.write(name,strlen(name));
   cout<<"------------"<<endl;
   cout<<iofs.tellg()<<endl;
   cout<<iofs.tellp()<<endl;
   iofs.seekp(-3,ios::cur);
   iofs<<12;
   cout<<iofs.tellg()<<endl;
   cout<<iofs.tellp()<<endl;
   iofs.seekp(-3,ios::cur);
   char data[5]={0};
   iofs.read(data,3);
   cout<<data<<endl;
   iofs.close();
}

//cat /dev/null>random.dat 清空文件
