#include <iostream>
using namespace std;
void decode(const char*src,const char*des,unsigned char key){

}
void encode(const char*src,const char*des){

}
int main(int argc,char **argv){
   if(argc<3){
      cout<<"程序使用错误"<<endl;
	  cout<<"加密: xor 源文件  加密文件"<<endl;
	  cout<<"解密：xor 源文件  解密文件  key"<<endl;
   }else if(argc==3){
      cout<<"文件加密"<<endl;
	  encode("a","b");
   }else{
      cout<<"文件解密"<<endl;
	  decode("b","d",1);
   }
}

/*
 root@test:/home/test/biaoc/C/qt/day01# g++  xor.cpp 
 root@test:/home/test/biaoc/C/qt/day01# ./a.out
 程序使用错误
 加密: xor 源文件  加密文件
 解密：xor 源文件  解密文件  key
 root@test:/home/test/biaoc/C/qt/day01# ./a.out  a b 
 文件加密
 root@test:/home/test/biaoc/C/qt/day01# ./a.out  a b  1
 文件解密


root@test:/home/test/biaoc/C/qt/day01# g++   xor.cpp  -o  xor 
root@test:/home/test/biaoc/C/qt/day01# ls
a.out  changevalue  closelab  closelab2  first  second  xor  xor.cpp
root@test:/home/test/biaoc/C/qt/day01# ./xor  a b   #把a加密成b
文件加密
root@test:/home/test/biaoc/C/qt/day01# ls
a.out  changevalue  closelab  closelab2  first  second  xor  xor.cpp
root@test:/home/test/biaoc/C/qt/day01# ./xor  b  c   100  #把b解密为c并加上密码100
文件解密
*/
