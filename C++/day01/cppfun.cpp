#include <iostream>
using namespace std;
//int testg();
void testg();
void getint(){
    cout<<"this is getint()"<<endl;
}
/*main 的返回值类型 可以省略 其它函数不可以*/
main(){
   testg();
   getint();
   //testg(1);
}
void testg(){
   cout<<"this is c++  function"<<endl;
}
