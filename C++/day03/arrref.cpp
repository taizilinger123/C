#include <iostream>
using namespace std;
void printArr(int data[5],int size=0){
   cout<<sizeof(data)<<endl;
   cout<<sizeof(data[0])<<endl; 
   for(int i=0;i<size/*sizeof data/sizeof(data[0])*/;i++){
      cout<<data[i]<<endl;
   }
}
/*使用引用*/
void printArrByRef(int (&data)[5]){
  for(int i=0;i<sizeof data/sizeof(data[0]);i++){
     cout<<data[i]<<endl;
  }
}
/*类型通用*/
template <typename T>
void printArrByTem(T& data){
  for(int i=0;i<sizeof data/sizeof(data[0]);i++){
     cout<<data[i]<<endl;
  } 
}
int main(){
   int data[5]={9,5,2,7,3};
   cout<<sizeof(data)<<endl;
   cout<<sizeof(data[0])<<endl;
   printArr(data,5);
   cout<<"----------------"<<endl;
   printArrByRef(data);
   printArrByTem(data);
}
