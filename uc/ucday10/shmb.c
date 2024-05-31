#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(){
  key_t key = ftok(".",100);
  int shmid = shmget(key,0,0);
  if(shmid==-1) perror("shmget"),exit(-1);
  void* p = shmat(shmid,0,0);
  if(p == (void*)-1) perror("shmat"),exit(-1);
  int x = *(int*)p;
  printf("x=%d\n",x);
  shmdt(p);
}

/*
 root@test:/home/test/biaoc/C/uc/ucday10# vi shmb.c
 root@test:/home/test/biaoc/C/uc/ucday10# gcc shmb.c -ob
 root@test:/home/test/biaoc/C/uc/ucday10# b
 x=12345
##########################################################
root@test:/home/test/biaoc/C/uc/ucday10# ipcs -m 

------------ 共享内存段 --------------
键        shmid      拥有者  权限     字节     连接数  状态      
0x00000000 65536      lightdm    600        524288     2          目标       
0x00000000 163841     lightdm    600        524288     2          目标       
0x00000000 229378     lightdm    600        67108864   2          目标       
0x64011a25 294915     root       666        4          0                       

root@test:/home/test/biaoc/C/uc/ucday10# ipcrm -m  65536
root@test:/home/test/biaoc/C/uc/ucday10# ipcs -m 

------------ 共享内存段 --------------
键        shmid      拥有者  权限     字节     连接数  状态      
0x00000000 65536      lightdm    600        524288     2          目标       
0x00000000 163841     lightdm    600        524288     2          目标       
0x00000000 229378     lightdm    600        67108864   2          目标       
0x64011a25 294915     root       666        4          0                       

root@test:/home/test/biaoc/C/uc/ucday10# ipcrm -m  294915
root@test:/home/test/biaoc/C/uc/ucday10# ipcs -m 

------------ 共享内存段 --------------
键        shmid      拥有者  权限     字节     连接数  状态      
0x00000000 65536      lightdm    600        524288     2          目标       
0x00000000 163841     lightdm    600        524288     2          目标       
0x00000000 229378     lightdm    600        67108864   2          目标
当使用删除命令/函数  删除共享内存时，不确保立即删除。只是给共享内存做一个删除标记，当挂接进程数为0才能真正删除。

 */
