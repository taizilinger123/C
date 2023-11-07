#include <stdio.h>
#include <unistd.h>

int main(){
   printf("pid=%d\n",getpid());
   int* p1 = sbrk(4);//映射1个内存页
   int* p2 = sbrk(4);//地址连续
   int* p3 = sbrk(4);
   int* p4 = sbrk(4);
   printf("p1=%p,p2=%p,p3=%p,p4=%p\n",p1,p2,p3,p4);
   *p1 = 10;*p2 = 20;*p3 = 30;*p4 = 40;
   sbrk(-4);//释放内存 4字节(只释放地址没有解除映射)
   sbrk(-8);//释放内存 8字节
   void* cur = sbrk(0);//取当前的位置->04
   printf("cur=%p\n",cur);//只有p1有效
   printf("*p1=%d,*p2=%d,*p3=%d\n",*p1,*p2,*p3);
   int* p5 = sbrk(4);//p2无效变量，被p5覆盖
   *p5 = 50;
   printf("*p2=%d\n",*p2);
   sbrk(4089);
   sleep(20);
   printf("sleep over\n");
   sbrk(-4097/*-1*/);
   while(1);
}
