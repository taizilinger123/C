#include <iostream>
using namespace std;
class A{
    int x;
	int y;
	public:
	A(){
	   x=100;
	   y=200;
	}
	void  show(){
	  cout<<x<<":"<<y<<endl;
	}
	void showint(int a){
	  cout<<a<<endl;
	}
};
int main(){
    A  a;
	cout<<"&a="<<&a<<endl;
	a.show();
	a.showint(123);
    cout<<"size="<<sizeof a<<endl;
	//cout<<a.x<<endl;
	int *pa=reinterpret_cast<int*>(&a);
    cout<<*pa<<endl;
	//得到y的值,指针加一
    cout<<*(pa+1)<<endl;
}

/*
 在main函数中加入以下2行进行调试
  17     cout<<"&a="<<&a<<endl;
   18     a.show();
   root@test:/home/test/biaoc/C/C++/day04# g++ -g  privatedata.cpp 
   root@test:/home/test/biaoc/C/C++/day04# ls
   a.out  mytime  privatedata.cpp  this.cpp  this.s
   root@test:/home/test/biaoc/C/C++/day04# gdb a.out
   (gdb) run a.out
   Starting program: /home/test/biaoc/C/C++/day04/a.out a.out
   &a=0x7fffffffe530
100:200
size=8
100
200
[Inferior 1 (process 5969) exited normally]
(gdb) b  main
Breakpoint 1 at 0x40099e: file privatedata.cpp, line 15.
(gdb) run a.out
Starting program: /home/test/biaoc/C/C++/day04/a.out a.out

Breakpoint 1, main () at privatedata.cpp:15
15	int main(){
(gdb) n
16	    A  a;
(gdb) n
17		cout<<"&a="<<&a<<endl;
(gdb) n
&a=0x7fffffffe530
18		a.show();
(gdb) s
A::show (this=0x7fffffffe530) at privatedata.cpp:12
12		  cout<<x<<":"<<y<<endl;
(gdb) exit
Undefined command: "exit".  Try "help".
(gdb) quit
A debugging session is active.

	Inferior 1 [process 5973] will be killed.
	
	Quit anyway? (y or n) y
#######################################
root@test:/home/test/biaoc/C/C++/day04# g++ -g  privatedata.cpp 
root@test:/home/test/biaoc/C/C++/day04# gdb a.out
(gdb) b main
Breakpoint 1 at 0x40099e: file privatedata.cpp, line 18.
(gdb) run a.out
Starting program: /home/test/biaoc/C/C++/day04/a.out a.out

Breakpoint 1, main () at privatedata.cpp:18
18	int main(){
(gdb) n
19	    A  a;
(gdb) n
20		cout<<"&a="<<&a<<endl;
(gdb) n
&a=0x7fffffffe530
21		a.show();
(gdb) s
A::show (this=0x7fffffffe530) at privatedata.cpp:12
12		  cout<<x<<":"<<y<<endl;
(gdb) n
100:200
13		}
(gdb) n
main () at privatedata.cpp:22
22		a.showint(123);
(gdb) s
A::showint (this=0x7fffffffe530, a=123) at privatedata.cpp:15
15		  cout<<a<<endl;

(gdb) quit
A debugging session is active.

	Inferior 1 [process 5985] will be killed.
	
	Quit anyway? (y or n) y
 */
