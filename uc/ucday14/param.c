#include <stdio.h>
#include <pthread.h>

void* task(void* p){
   int* pi = (int*)p;
   printf("task:%d\n",*pi);
   *pi = 200;
}
int main(){
   pthread_t id1;
   int x = 100;
   pthread_create(&id1,0,task,&x);//&x传给task
   //sleep(1);
   pthread_join(id1,0);//主线程等待id1 结束，比sleep(1)快
   printf("main:%d\n",x);
}
