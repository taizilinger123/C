#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(){
  key_t key = ftok(".",100);//1 得key
  if(key==-1) perror("ftok"),exit(-1);
  int shmid = shmget(key,4,//2 得内部ID
	IPC_CREAT|IPC_EXCL|0666);//创建而不获取
  if(shmid == -1) perror("shmget"),exit(-1);
  printf("共享内存创建完毕\n");
  void* p = shmat(shmid,0,0);//3 挂接
  if(p == (void*)-1) perror("shmat"),exit(-1);
  int* pi = p;//4 使用
  *pi = 12345;//把数据放入共享内存
  shmdt(p);//5 脱接
}//练习:写shmb.c 实现把12345 从共享内存中取出

/*
 root@test:/home/test/biaoc/C/uc/ucday10# vi  shma.c
 root@test:/home/test/biaoc/C/uc/ucday10# gcc shma.c -oa
 root@test:/home/test/biaoc/C/uc/ucday10# ipcs -m 

 ------------ 共享内存段 --------------
 键        shmid      拥有者  权限     字节     连接数  状态      
 0x00000000 65536      lightdm    600        524288     2          目标       
 0x00000000 163841     lightdm    600        524288     2          目标       
 0x00000000 229378     lightdm    600        67108864   2          目标       

 root@test:/home/test/biaoc/C/uc/ucday10# a
 共享内存创建完毕
 root@test:/home/test/biaoc/C/uc/ucday10# ipcs -m 

 ------------ 共享内存段 --------------
 键        shmid      拥有者  权限     字节     连接数  状态      
 0x00000000 65536      lightdm    600        524288     2          目标       
 0x00000000 163841     lightdm    600        524288     2          目标       
 0x00000000 229378     lightdm    600        67108864   2          目标       
 0x64011a25 262147     root       666        4          0                       

 root@test:/home/test/biaoc/C/uc/ucday10# a
shmget: File exists
root@test:/home/test/biaoc/C/uc/ucday10# ipcrm -m 262147
root@test:/home/test/biaoc/C/uc/ucday10# a
共享内存创建完毕
root@test:/home/test/biaoc/C/uc/ucday10# ipcs -m 

------------ 共享内存段 --------------
键        shmid      拥有者  权限     字节     连接数  状态      
0x00000000 65536      lightdm    600        524288     2          目标       
0x00000000 163841     lightdm    600        524288     2          目标       
0x00000000 229378     lightdm    600        67108864   2          目标       
0x64011a25 294915     root       666        4          0             
 */
