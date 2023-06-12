#include <iostream>
#include <fstream>
using namespace std;
int main(){
   ifstream  ifs("animal.cpp");
   if(!ifs){
      cout<<"open file failed"<<endl;
   }
   char c;
   /*while((c=ifs.get())!=EOF){
      cout.put(c);
   }*/
   while(ifs>>c){
	  /*格式化输入 考虑一下写在内部和循环中的区别*/
      //ifs>>c;
	  cout.put(c);
   }
   ifs.close();
   /*使用ifs.get(c)读取文件 然后完成复制文件*/
}
