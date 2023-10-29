#include <stdio.h>
#include <unistd.h>

int main(){
   printf("pid=%d\n",getpid());
   void* p1 = sbrk(4);//映射1个内存页
   void* p2 = sbrk(4);//地址连续
   void* p3 = sbrk(4);
   void* p4 = sbrk(4);
   printf("p1=%p,p2=%p,p3=%p,p4=%p\n",p1,p2,p3,p4);
   while(1);
}
