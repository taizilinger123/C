#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void fa(int signo){
   printf("捕获了信号%d\n",signo);
}
int main(){
   signal(SIGINT,fa);//2  ctrl+c
   signal(SIGQUIT,SIG_IGN); //3 被忽略
   pid_t pid = vfork();
   if(pid == 0){//子进程执行
      printf("child pid=%d\n",getpid());
	  execl("./proc","proc",NULL);
   }
   printf("父进程退出\n");
}

/*
 root@test:/home/test/biaoc/C/uc/ucday08# gcc sigchild2.c 
 root@test:/home/test/biaoc/C/uc/ucday08# ls
 a.out  sigchild2.c  sigchild.c  signal.c
 root@test:/home/test/biaoc/C/uc/ucday08# vi proc.c
 root@test:/home/test/biaoc/C/uc/ucday08# cat  proc.c 
 int main(){
   while(1);
   }
   root@test:/home/test/biaoc/C/uc/ucday08# gcc proc.c -oproc
   root@test:/home/test/biaoc/C/uc/ucday08# ls
   a.out  proc  proc.c  sigchild2.c  sigchild.c  signal.c
   root@test:/home/test/biaoc/C/uc/ucday08# a.out
   child pid=3754
   父进程退出
   root@test:/home/test/biaoc/C/uc/ucday08# kill  -3 3754 #被忽略
   root@test:/home/test/biaoc/C/uc/ucday08# kill  -3 3754
   root@test:/home/test/biaoc/C/uc/ucday08# kill  -3 3754
   root@test:/home/test/biaoc/C/uc/ucday08# kill  -2 3754 #恢复默认 
   root@test:/home/test/biaoc/C/uc/ucday08# kill  -2 3754 
   -su: kill: (3754) - 没有那个进程
 */
