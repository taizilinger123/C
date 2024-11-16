#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
char* data[5];//最多存5个人名
int size = 0;//人数，数组下标
sem_t sem;//1 声明
void* task(void* p){
  sem_wait(&sem);//3 上锁
  data[size] = p;//4 执行代码
  sleep(1);
  size++;
  sem_post(&sem);//5 解锁
} 
int main(){
  sem_init(&sem,0,1);//2 初始化
  data[size] = "liubei";
  size++;
  pthread_t id1,id2;
  pthread_create(&id1,0,task,(void*)"guanyu");
  pthread_create(&id2,0,task,(void*)"zhangfei");
  pthread_join(id1,0);
  pthread_join(id2,0);
  sem_destroy(&sem);//6 销毁
  int i;
  for(i=0;i<size;i++){
	 printf("%p\n",data[i]);
     printf("%s\n",data[i]);
  }
}

/*
root@test:/home/test/biaoc/C/uc/ucday14# gcc sem.c  -pthread
sem.c: In function ‘task’:
sem.c:10:3: warning: implicit declaration of function ‘sleep’ [-Wimplicit-function-declaration]
sleep(1);
^
root@test:/home/test/biaoc/C/uc/ucday14# a.out
0x400ab4
liubei
0x400abb
guanyu
0x400ac2
zhangfei
*/
