#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
  pid_t  pid1 = fork();
  pid_t  pid2;
  if(pid1 > 0) pid2 = fork();//父进程执行
  /*
   8.9两行可以写成
   if(pid1>0){
      pid_t pid2 = fork();
   }
   */
  if(pid1==0){//子进程1执行
    printf("子进程A执行,pid=%d,休眠3秒\n",getpid());
	sleep(3);
	printf("子进程A结束\n");
	exit(10);
  }
  printf("over\n");
}
