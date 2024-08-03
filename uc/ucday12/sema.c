#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <signal.h>
int semid;
void fa(int signo){
  printf("准备删除信号量集\n");
  semctl(semid,0,IPC_RMID);
}
int main(){
   signal(SIGINT,fa);
   key_t  key = ftok(".",100);
   semid = semget(key,1,IPC_CREAT|0666);
   //1是数组长度
   if(semid == -1) perror("semget"),exit(-1);
   if(semctl(semid,0,SETVAL,5)==-1)
	 perror("semctl"),exit(-1);
   else printf("成功初始化为5\n");
   pause();//暂停函数，直到有新的信号到来
   //while(1);
}//练习：实现用信号SIGINT删除  信号量集

/*
 root@test:/home/test/biaoc/C/uc/ucday12# gcc sema.c  -oa
 root@test:/home/test/biaoc/C/uc/ucday12# a
 成功初始化为5
 root@test:/home/test/biaoc/C/uc/ucday12# ipcs  -s 

 --------- 信号量数组 -----------
 键        semid      拥有者  权限     nsems     
 0x64010e0f 0          root       666        1    
###############################################
root@test:/home/test/biaoc/C/uc/ucday12# gcc sema.c 
sema.c: In function ‘main’:
sema.c:20:4: warning: implicit declaration of function ‘pause’ [-Wimplicit-function-declaration]
pause();//暂停函数，直到有新的信号到来
^
root@test:/home/test/biaoc/C/uc/ucday12# ipcs -s 

--------- 信号量数组 -----------
键        semid      拥有者  权限     nsems     

root@test:/home/test/biaoc/C/uc/ucday12# gcc sema.c -oa
sema.c: In function ‘main’:
sema.c:20:4: warning: implicit declaration of function ‘pause’ [-Wimplicit-function-declaration]
pause();//暂停函数，直到有新的信号到来
^
root@test:/home/test/biaoc/C/uc/ucday12# a
成功初始化为5
^C准备删除信号量集
root@test:/home/test/biaoc/C/uc/ucday12# ipcs -s 

--------- 信号量数组 -----------
键        semid      拥有者  权限     nsems     )])]
*/
