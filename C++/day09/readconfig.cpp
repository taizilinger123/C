#include <iostream>
#include <fstream>
using namespace std;
int main(){
   ifstream ifs("config.txt");
   if(!ifs){
      perror("open file failed");
   }
   string ip;
   getline(ifs,ip,'=');
   getline(ifs,ip);
   cout<<ip<<endl;
   ifs.ignore(30,'=');
   short  port;
   ifs>>port;
   cout<<port<<endl;   
   string name;
   getline(ifs,name,'=');
   getline(ifs,name);
   cout<<name<<endl;
   ifs.close();
}
