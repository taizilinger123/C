#include <stdio.h>
#include <stdlib.h>

int main(){
   int a,b,c,d;//栈
   printf("a=%p,b=%p,c=%p,d=%p\n",&a,&b,&c,&d);
   int *p1 = malloc(4);//虽然申请的4但映射33页
   int *p2 = malloc(8);//不需要再次映射
   int *p3 = malloc(16);
   int *p4 = malloc(4);
   *(p1+200) = 10;// p1+200 已映射
   printf("%d\n",*(p1+200));//能打印
   printf("p1=%p,p2=%p,p3=%p,p4=%p\n",p1,p2,p3,p4);
   printf("pid=%d\n",getpid());
   *(p1-1) = 0;//清p1前面4个字节,额外信息被清
   free(p1);
   //free(p2);
   while(1);
}
