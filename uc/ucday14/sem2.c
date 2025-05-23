#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <time.h>

sem_t sem;
void* task(void* p){
  int i = (int)p;
  printf("线程%d启动,申请连接\n",i);
  sem_wait(&sem);
  printf("线程%d申请成功\n",i);
  srand(time(0));
  sleep(rand()%10);
  printf("线程%d完成使用, 释放连接\n",i);
  sem_post(&sem);
}
int main(){
  sem_init(&sem,0,10);
  int i;
  pthread_t id[20];
  for(i=0;i<20;i++){
	pthread_create(&id[i],0,task,(void*)(i+1));
  }
  for(i=0;i<20;i++){
    pthread_join(id[i],0);
  }
  sem_destroy(&sem);
}
