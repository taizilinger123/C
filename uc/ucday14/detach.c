#include <stdio.h>
#include <pthread.h>

void* task(void* p){
  int i;
  for(i=0;i<30;i++){
    printf("%d\n",i);
	usleep(100000);
  }
}
int main(){
  pthread_t id;
  pthread_create(&id,0,task,0);
  pthread_detach(id);
  pthread_join(id,0);//join放detach后没效果
  //pthread_detach(id);//detach放join后无意义
  int i;
  for(i=0;i<30;i++){
    printf("A\n");
	usleep(100000);
  }
}
