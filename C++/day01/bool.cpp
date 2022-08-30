#include <iostream>
using namespace std;
int main(){
   bool flag=false;
   flag="abc";
   flag=10;
   /*表达假的四个 NULL 0 '\0' false */
   flag=NULL;
   if(flag){
       cout<<flag<<" flag is true"<<endl;
   }else{
       cout<<flag<<" flag is false"<<endl;
   }
   int days=28;
   if(flag){
      days+=flag;
   }
}
