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
  if(pid2==0){//子进程2执行
    printf("子进程B执行,pid=%d,休眠1秒\n",getpid());
	sleep(1);
	printf("子进程B结束\n");
	exit(20);
  }
  printf("父进程准备等待\n");
  int res;
  waitpid(-1,&res,0);//0阻塞 WNOHANG非阻塞
  //waitpid(pid1,&res,0);//0阻塞 WNOHANG非阻塞
  if(WIFEXITED(res))
	printf("父进程:%d\n",WEXITSTATUS(res));
}

/*
 root@test:/home/test/biaoc/C/uc/ucday08# gcc  waitpid.c 
 root@test:/home/test/biaoc/C/uc/ucday08# a.out
 子进程A执行,pid=11637,休眠3秒
 父进程准备等待
 子进程B执行,pid=11638,休眠1秒
 子进程B结束
 子进程A结束
 父进程:10
 root@test:/home/test/biaoc/C/uc/ucday08# vi  waitpid.c
 root@test:/home/test/biaoc/C/uc/ucday08# gcc  waitpid.c 
 root@test:/home/test/biaoc/C/uc/ucday08# a.out
 父进程准备等待
 子进程B执行,pid=11651,休眠1秒
 子进程A执行,pid=11650,休眠3秒
 子进程B结束
 父进程:20
 root@test:/home/test/biaoc/C/uc/ucday08# 子进程A结束

 */
