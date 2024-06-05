#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
//练习: 取一下共享内存的属性，打印权限和大小
//修改共享内存的权限为: 0640
//前面两个练习做好后 加入删除的代码并执行删除
int main(){
   key_t key = ftok(".",100);
   int shmid = shmget(key,0,0);
   if(shmid == -1) perror("shmget"),exit(-1);
   struct shmid_ds ds;
   shmctl(shmid,IPC_STAT,&ds);//ds中有属性
   printf("size=%d\n",ds.shm_segsz);
   printf("mode=%o\n",ds.shm_perm.mode);
   printf("nattch=%d\n",ds.shm_nattch);
   //修改
   ds.shm_perm.mode = 0640;//权限  可以改
   ds.shm_segsz = 400;//大小 没有效果
   shmctl(shmid,IPC_SET,&ds);
   shmctl(shmid,IPC_RMID,0);//删除
}
/*
 root@test:/home/test/biaoc/C/uc/ucday10# ipcs -m 

 ------------ 共享内存段 --------------
 键        shmid      拥有者  权限     字节     连接数  状态      
 0x00000000 65536      lightdm    600        524288     2          目标       
 0x00000000 163841     lightdm    600        524288     2          目标       
 0x00000000 229378     lightdm    600        67108864   2          目标       
 0x64011a25 327683     root       666        4          0              
root@test:/home/test/biaoc/C/uc/ucday10# gcc  shmctl.c 
shmctl.c: In function ‘main’:
shmctl.c:14:11: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘size_t {aka long unsigned int}’ [-Wformat=]
printf("size=%d\n",ds.shm_segsz);
^
shmctl.c:16:11: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘shmatt_t {aka long unsigned int}’ [-Wformat=]
printf("nattch=%d\n",ds.shm_nattch);
^
root@test:/home/test/biaoc/C/uc/ucday10# a.out
size=4
mode=666
nattch=0
root@test:/home/test/biaoc/C/uc/ucday10# ipcs  -m 

------------ 共享内存段 --------------
键        shmid      拥有者  权限     字节     连接数  状态      
0x00000000 65536      lightdm    600        524288     2          目标       
0x00000000 163841     lightdm    600        524288     2          目标       
0x00000000 229378     lightdm    600        67108864   2          目标       
0x64011a25 327683     root       640        4          0            
 */
