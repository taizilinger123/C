#include <stdio.h>
#include <pthread.h>

void* task1(void* p){
   pthread_setcancelstate(//设置能否取消
	 PTHREAD_CANCEL_DISABLE,0);//PTHREAD_CANCEL_ENABLE
   pthread_setcanceltype(//设置立即/取消点
     PTHREAD_CANCEL_DEFERRED,0);//PTHREAD_CANCEL_ASYNCHRONOUS
   while(1){
     printf("I am superman\n");
	 usleep(1);
   }
}
void* task2(void* p){
  sleep(3);
  printf("cancel......\n");
  pthread_cancel(*(pthread_t*)p);
}
int main(){
  pthread_t id1,id2;
  pthread_create(&id1,0,task1,0);
  pthread_create(&id2,0,task2,0);
  pthread_join(id1,0);
  pthread_join(id2,0);
}
