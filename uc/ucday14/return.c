#include <stdio.h>
#include <pthread.h>
#include <string.h>
//不能返回指向局部变量(栈区)的地址，static除外
char* get(){
   char* str = "abcd";
   return str;//可以返回
   //char str[] = "abcd";
   //return str;//返回出错
}
int test(){//局部变量的值可以返回
   int x = 3;
   return x;
}
void* task(void* p){//返回1-10的和
   int i; 
   static int sum = 0;
   for(i=1;i<11;i++){
     sum = sum+i;
   }
   return &sum;//pi=*returnvalue=&sum;
}
int main(){
   char* s = get();
   printf("s=%s\n",s);
   pthread_t id;
   pthread_create(&id,0,task,0);
   int* pi;//野指针,*pi不靠谱,pi变量存在
   pthread_join(id,(void**)&pi);//&pi不是野指针
   printf("*pi=%d\n",*pi);
}

/*
 root@test:/home/test/biaoc/C/uc/ucday14# vi return.c
 root@test:/home/test/biaoc/C/uc/ucday14# gcc  return.c -pthread
 root@test:/home/test/biaoc/C/uc/ucday14# a.out
 s=abcd
 *pi=55
 */
