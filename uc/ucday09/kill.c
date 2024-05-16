#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void fa(int signo){
  printf("捕获了信号%d\n",signo);
}
int main(){
  pid_t pid = fork();
  if(pid==0){
      signal(SIGINT,fa);
	  printf("pid=%d\n",getpid());
	  while(1);
  }
  printf("父进程给子进程发送信号\n");
  kill(pid,SIGINT);
}


/*
ps  -aux
 test@test:~$ kill  -0  5027
 -su: kill: (5027) - 不允许的操作
 test@test:~$ kill  -0  6523
 -su: kill: (6523) - 没有那个进程

################################################
root@test:/home/test/biaoc/C/uc/ucday09# gcc  kill.c 
root@test:/home/test/biaoc/C/uc/ucday09# a.out
父进程给子进程发送信号
root@test:/home/test/biaoc/C/uc/ucday09# ps 
PID TTY          TIME CMD
2340 pts/8    00:00:00 sudo
2341 pts/8    00:00:00 su
2342 pts/8    00:00:02 bash
6632 pts/8    00:00:00 a.out
6726 pts/8    00:00:00 ps
root@test:/home/test/biaoc/C/uc/ucday09# kill -2 6632
root@test:/home/test/biaoc/C/uc/ucday09# ps 
PID TTY          TIME CMD
2340 pts/8    00:00:00 sudo
2341 pts/8    00:00:00 su
2342 pts/8    00:00:02 bash
6632 pts/8    00:00:00 a.out
6727 pts/8    00:00:00 ps
root@test:/home/test/biaoc/C/uc/ucday09# kill -2 6632
root@test:/home/test/biaoc/C/uc/ucday09# kill -2 6632
root@test:/home/test/biaoc/C/uc/ucday09# kill -2 6632
root@test:/home/test/biaoc/C/uc/ucday09# ps 
PID TTY          TIME CMD
2340 pts/8    00:00:00 sudo
2341 pts/8    00:00:00 su
2342 pts/8    00:00:02 bash
6632 pts/8    00:00:00 a.out
6729 pts/8    00:00:00 ps
root@test:/home/test/biaoc/C/uc/ucday09# killall a.out
root@test:/home/test/biaoc/C/uc/ucday09# ps 
PID TTY          TIME CMD
2340 pts/8    00:00:00 sudo
2341 pts/8    00:00:00 su
2342 pts/8    00:00:02 bash
6731 pts/8    00:00:00 ps
:32,62left 再次按enter回车就32到62靠左对齐了  vi那些行靠左对齐
 */
