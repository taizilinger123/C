#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main(){
   key_t  key = ftok(".",100);
   int semid = semget(key,1,IPC_CREAT|0666);
   //1是数组长度
   if(semid == -1) perror("semget"),exit(-1);
   if(semctl(semid,0,SETVAL,5)==-1)
	 perror("semctl"),exit(-1);
   else printf("成功初始化为5\n");
}

/*
 root@test:/home/test/biaoc/C/uc/ucday12# gcc sema.c  -oa
 root@test:/home/test/biaoc/C/uc/ucday12# a
 成功初始化为5
 root@test:/home/test/biaoc/C/uc/ucday12# ipcs  -s 

 --------- 信号量数组 -----------
 键        semid      拥有者  权限     nsems     
 0x64010e0f 0          root       666        1    
 */
