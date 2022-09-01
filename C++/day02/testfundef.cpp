#include "fundef.h"
#include <iostream>
using namespace std;
int getmax(int x,int y){
   return x>y?x:y;
}
int main(){
    cout<<getmax(1)<<endl;
}
