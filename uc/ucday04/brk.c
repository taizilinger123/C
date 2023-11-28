#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main(){
    void*  p = sbrk(0);//取初始位置
	int r = brk(p+4);//分配4字节
    if(r==-1) perror("brk"),exit(-1);//,连接一个语句，省略{}
    brk(p+8);//分配4字节
	brk(p+4);//释放4字节
	int* pi = p;
	*pi = 100;
	double* pd = sbrk(0);
	brk(pd+1);
	*pd = 3.14;
	char* p2 = sbrk(0);
	brk(p2+10);
	//p2 = "hello";//错!
	strcpy(p2,"hello");
	printf("pd=%p,p2=%p\n",pd,p2);
	printf("*pi=%d,*pd=%lf,p2=%s\n",*pi,*pd,p2);
	brk(p);//释放全部内存
	//sbrk()用申请用
	//brk()用释放用
}
