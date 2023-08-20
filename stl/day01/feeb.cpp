#include <iostream>
#include <typeinfo>
//typeinfo是打印T的类型
using namespace std;
template<typename T>
class Feeb {
public:
   Feeb(void){
     cout<< "Feeb<T>: "<<typeid(T).name()<<endl;
   }
};

template<typename T>
class Feeb<T[]>{
//特化没有具体的数组的数字下面的也不能写具体的数组数字
public:
   Feeb (void) {
     cout << "Feeb<T[]>: "<<typeid(T).name()<<endl; 
   }
};
template<typename T>
class Feeb<T*>{
public:
  Feeb(void){
    cout<<"Feeb<T*>: "<<typeid(T).name()<<endl;
  }
};

int main(void){
   Feeb<char> f1;
   Feeb<char[]> f2;//这里跟特化数组保持一致，不能写具体的数字
   Feeb<char*> f3;
   Feeb<char*****> f4;
   return 0;
}
/*
 root@test:/home/test/biaoc/C/stl/day01# vi feeb.cpp
 root@test:/home/test/biaoc/C/stl/day01# g++ feeb.cpp 
 root@test:/home/test/biaoc/C/stl/day01# ./a.out 
 Feeb<T>: c
 Feeb<T[]>: c
 Feeb<T*>: c
 Feeb<T*>: PPPPc
 */
