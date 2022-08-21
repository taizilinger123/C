#include <iostream>
using namespace std;
namespace  ns1{
     int a=1;
     namespace  ns2{
	        int b=2;
	        namespace ns3{
			    int a=3;
			    void  show(){
					cout<<a<<endl;
					cout<<ns1::a<<endl;
				}
			}
     }
}
/*给嵌套的命名空间名  重新起名字 */
namespace ns4=ns1::ns2::ns3;
int main(){
   ns1::ns2::ns3::show();
   using  ns1::a;
   cout<<a<<endl;
   using namespace ns1::ns2;
   ns3::show();
   ns4::show();
}
