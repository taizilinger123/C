#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* task(void* p){
  static int i;
  for(i=0;i<100;i++){
     printf("i=%d\n",i);
	 if(i == 10)
	   //return &i;//结束线程，返回&i
	   //pthread_exit((void*)&i);//与return一样
	   exit(i);//退出进程
  }
}
int main(){
  pthread_t  id;
  pthread_create(&id,0,task,0);
  int* pi;
  pthread_join(id,(void**)&pi);
  printf("main over,*pi=%d\n",*pi);
}
