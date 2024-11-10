#include <stdio.h>
#include <pthread.h>
#include <string.h>

void* task(void* p){
  printf("我是一个线程\n");
}
int main(){
   pthread_t id;
   printf("size=%d\n",sizeof(id));
   int res = pthread_create(&id,0,task,0);
   if(res) printf("error:%s\n",strerror(res));
   pthread_t id2 = pthread_self();//取当前线程ID
   printf("id=%u,id2=%u\n",id,id2);
   sleep(1);//确保主线程最后结束
}
/*
 root@test:/home/test/biaoc/C/uc/ucday14# gcc pthread.c -lpthread
 pthread.c: In function ‘main’:
 pthread.c:10:11: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long unsigned int’ [-Wformat=]
     printf("size=%d\n",sizeof(id));
	            ^
				pthread.c:14:11: warning: format ‘%u’ expects argument of type ‘unsigned int’, but argument 2 has type ‘pthread_t {aka long unsigned int}’ [-Wformat=]
				    printf("id=%u,id2=%u\n",id,id2);
					           ^
							   pthread.c:14:11: warning: format ‘%u’ expects argument of type ‘unsigned int’, but argument 3 has type ‘pthread_t {aka long unsigned int}’ [-Wformat=]
							   pthread.c:15:4: warning: implicit declaration of function ‘sleep’ [-Wimplicit-function-declaration]
							       sleep(1);
								       ^
									   root@test:/home/test/biaoc/C/uc/ucday14# a.out
									   size=8
									   id=4276532992,id2=4284864256
									   我是一个线程
									   root@test:/home/test/biaoc/C/uc/ucday14# gcc pthread.c -pthread
									   pthread.c: In function ‘main’:
									   pthread.c:10:11: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long unsigned int’ [-Wformat=]
									       printf("size=%d\n",sizeof(id));
										              ^
													  pthread.c:14:11: warning: format ‘%u’ expects argument of type ‘unsigned int’, but argument 2 has type ‘pthread_t {aka long unsigned int}’ [-Wformat=]
													      printf("id=%u,id2=%u\n",id,id2);
														             ^
																	 pthread.c:14:11: warning: format ‘%u’ expects argument of type ‘unsigned int’, but argument 3 has type ‘pthread_t {aka long unsigned int}’ [-Wformat=]
																	 pthread.c:15:4: warning: implicit declaration of function ‘sleep’ [-Wimplicit-function-declaration]
																	     sleep(1);
																		     ^
																			 root@test:/home/test/biaoc/C/uc/ucday14# a.out
																			 size=8
																			 id=461752064,id2=470083328
																			 我是一个线程
 */
