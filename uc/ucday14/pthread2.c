#include <stdio.h>
#include <pthread.h>

void* task(void* p){
  int i;
  for(i=0;i<100;i++){
    printf("in task:i=%d\n",i);
  }
}
int main(){
  pthread_t id;
  pthread_create(&id,0,task,0);
  int i;
  for(i=0;i<100;i++){
    printf("main:i=%d\n",i);
  }
  sleep(1);
}
