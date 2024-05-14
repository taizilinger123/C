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
   pid_t pid = fork();//子进程照抄父进程的处理
   if(pid == 0){//子进程执行
      printf("child pid=%d\n",getpid());
	  while(1);
   }
   printf("父进程退出\n");
}
/*
root@test:/home/test/biaoc/C/uc/ucday08# gcc  sigchild.c
 root@test:/home/test/biaoc/C/uc/ucday08# a.out
 父进程退出
 child pid=2767
 root@test:/home/test/biaoc/C/uc/ucday08# kill -2 2767
 捕获了信号2
 root@test:/home/test/biaoc/C/uc/ucday08# kill -2 2767
 捕获了信号2
 root@test:/home/test/biaoc/C/uc/ucday08# kill -2 2767
 捕获了信号2
 root@test:/home/test/biaoc/C/uc/ucday08# kill -3 2767
 root@test:/home/test/biaoc/C/uc/ucday08# kill -3 2767
 root@test:/home/test/biaoc/C/uc/ucday08# kill -3 2767
 root@test:/home/test/biaoc/C/uc/ucday08# ps
   PID TTY          TIME CMD
    2340 pts/8    00:00:00 sudo
	 2341 pts/8    00:00:00 su
	  2342 pts/8    00:00:00 bash
	   2767 pts/8    00:00:37 a.out
	    2768 pts/8    00:00:00 ps
			   root@test:/home/test/biaoc/C/uc/ucday08# kill -9 2767
			   root@test:/home/test/biaoc/C/uc/ucday08# ps
			     PID TTY          TIME CMD
				  2340 pts/8    00:00:00 sudo
				   2341 pts/8    00:00:00 su
				    2342 pts/8    00:00:00 bash
					 2770 pts/8    00:00:00 ps

 */
