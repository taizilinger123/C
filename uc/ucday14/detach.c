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
  pthread_detach(id);//确保线程结束立即回收资源
  //pthread_join(id,0);//join放detach后没效果
  //pthread_detach(id);//detach放join后无意义
  int i;
  for(i=0;i<30;i++){
    printf("A\n");
	usleep(100000);
  }
}

/*
 root@test:/home/test/biaoc/C/uc/ucday14# gcc  detach.c -pthread
 detach.c: In function ‘task’:
 detach.c:8:2: warning: implicit declaration of function ‘usleep’ [-Wimplicit-function-declaration]
   usleep(100000);
     ^
	 root@test:/home/test/biaoc/C/uc/ucday14# a.out 
	 A
	 0
	 1
	 A
	 A
	 2
	 3
	 A
	 A
	 4
	 A
	 5
	 6
	 A
	 7
	 A
	 A
	 8
	 A
	 9
	 A
	 10
	 A
	 11
	 12
	 A
	 13
	 A
	 14
	 A
	 15
	 A
	 16
	 A
	 17
	 A
	 18
	 A
	 19
	 A
	 20
	 A
	 21
	 A
	 22
	 A
	 23
	 A
	 24
	 A
	 25
	 A
	 26
	 A
	 27
	 A
	 28
	 A
	 29
	 A
 */
