#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(){
   key_t key = ftok(".",100);
   if(key == -1) perror("ftok"),exit(-1);
   int msgid = msgget(key,0666|IPC_CREAT);
   if(msgid == -1) perror("msgid"),exit(0);
   int res = msgsnd(msgid,"hello msg",9,0);
   if(res == -1) perror("msgsnd"),exit(-1);
   printf("发送成功\n");
}

/*
 root@test:/home/test/biaoc/C/uc/ucday10# gcc  msga.c  -oa 
 root@test:/home/test/biaoc/C/uc/ucday10# ipcs -q

 --------- 消息队列 -----------
 键        msqid      拥有者  权限     已用字节数 消息      

 root@test:/home/test/biaoc/C/uc/ucday10# a
 发送成功
 root@test:/home/test/biaoc/C/uc/ucday10# ipcs -q

 --------- 消息队列 -----------
 键        msqid      拥有者  权限     已用字节数 消息      
 0x64011a25 0          root       666        9            1           

 root@test:/home/test/biaoc/C/uc/ucday10# a
 发送成功
 root@test:/home/test/biaoc/C/uc/ucday10# ipcs -q

 --------- 消息队列 -----------
 键        msqid      拥有者  权限     已用字节数 消息      
 0x64011a25 0          root       666        18           2   
 */
