#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

int main(){
   key_t  key = ftok(".",100);
   int semid = semget(key,0,0);//获取时长度为0
   if(semid == -1) perror("semget"),exit(-1);
   int i;
   for(i=0;i<10;i++){
     pid_t  pid = fork();
	 if(pid==0){//子进程执行代码
	    struct sembuf op;
		op.sem_num = 0;//信号量数组的下标
		op.sem_op  = -1;//信号量计数-1
		op.sem_flg = 0;//阻塞，IPC_NOWAIT非阻塞
		semop(semid,&op,1);//数组的首地址就是第一个元素的首地址
		printf("访问共享资源\n");
		sleep(10);
		op.sem_op = 1;
		semop(semid,&op,1);
		exit(0);
	 }
   }//循环创建10个子进程，子进程不会创建子进程
}

/*
root@test:/home/test/biaoc/C/uc/ucday12# gcc semb.c -ob
root@test:/home/test/biaoc/C/uc/ucday12# b
访问共享资源
访问共享资源
访问共享资源
访问共享资源
访问共享资源
root@test:/home/test/biaoc/C/uc/ucday12# ps
PID TTY          TIME CMD
7988 pts/8    00:00:00 sudo
7989 pts/8    00:00:00 su
7990 pts/8    00:00:02 bash
17346 pts/8    00:00:00 b
17347 pts/8    00:00:00 b
17348 pts/8    00:00:00 b
17349 pts/8    00:00:00 b
17350 pts/8    00:00:00 b
17351 pts/8    00:00:00 b
17352 pts/8    00:00:00 b
17353 pts/8    00:00:00 b
17354 pts/8    00:00:00 b
17355 pts/8    00:00:00 b
17356 pts/8    00:00:00 ps
root@test:/home/test/biaoc/C/uc/ucday12# 访问共享资源
访问共享资源
访问共享资源
访问共享资源
访问共享资源
 */
