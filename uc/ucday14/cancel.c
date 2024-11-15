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

/*
 *(pthread_t*)p
指针前面加个*就是得到指针的具体的东西
int x = 10;
int* p = &x;  // p 是一个指向 x 的指针，保存了 x 的地址

printf("地址 p 是: %p\n", (void*)p);    // 输出指针 p 的值（即 x 的地址）
printf("值 *p 是: %d\n", *p);          // 输出 p 指向的内容，即 x 的值""))"")
 */
