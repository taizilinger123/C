#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* task(void* p){ //非常规用法
  int a = (int)p;//直接使用int
  printf("a=%d\n",a);
}
void* task2(void* p){
  printf("*p=%d\n",*(int*)p);
}
int main(){
  int x = 100;
  pthread_t id;
  pthread_create(&id,0,task,(void*)x);//传int
  pthread_join(id,0);
  int* pi = malloc(4);
  *pi = 300;
  pthread_create(&id,0,task2,pi);
  //free(pi);//如果使用堆内存，一定保证线程结束后再释放内存
  pthread_join(id,0);
}
