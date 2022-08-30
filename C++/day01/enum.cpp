#include <iostream>
using namespace std;
enum Direction{D_UP,D_DOWN,D_LEFT,D_RIGHT};
int main(){
  Direction  dire=D_DOWN;
  cout<<dire<<endl;
  /*枚举一定是整数*/
  int        x=dire;
  cout<<x<<endl;
  //dire=x;
  dire=D_RIGHT;
  cout<<dire<<endl;
}
