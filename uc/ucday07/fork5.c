#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  printf("进程%d开始运行\n",getpid());
  pid_t pid = fork();
  if(pid==0){//子进程
    printf("我的父进程是%d\n",getppid());
	sleep(3);
	printf("睡眠结束，新的父进程是%d\n",getppid());
	exit(0);
  }
  sleep(1);
  printf("父进程%d结束了\n",getpid());
}

/*
 root@test:/home/test/biaoc/C/uc/ucday07# a.out
 进程2889开始运行
 我的父进程是2889
 父进程2889结束了
 root@test:/home/test/biaoc/C/uc/ucday07# 睡眠结束，新的父进程是1
 */
