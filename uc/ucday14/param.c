#include <stdio.h>
#include <pthread.h>

void* task(void* p){
   int* pi = (int*)p;
   printf("task:%d\n",*pi);
   *pi = 200;
}
void* task2(void* p){
   double* pd = p;
   printf("s=%lf\n",(*pd)*(*pd)*3.14);
}
struct param{
   int a;
   int b;
};
void* task3(void* p){
  struct param* pp = p;
  printf("sum=%d\n",pp->a + pp->b);
}
int main(){
   pthread_t id1,id2,id3;
   int x = 100;
   pthread_create(&id1,0,task,&x);//&x传给task
   //sleep(1);
   pthread_join(id1,0);//主线程等待id1 结束，比sleep(1)快
   printf("main:%d\n",x);
   double d = 1.0;
   pthread_create(&id2,0,task2,&d);
   pthread_join(id2,0);
   struct param pa = {2,3};
   pthread_create(&id3,0,task3,&pa);
   pthread_join(id3,0);
}
