#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct MSG{
  long mtype;//消息类型
  char buf[256];//数据
};
int main(){
  key_t key = ftok(".",100);
  int msgid = msgget(key,0666|IPC_CREAT);
  if(msgid == -1) perror("msgget"),exit(-1);
  struct MSG msg1,msg2;
  msg1.mtype = 1;strcpy(msg1.buf,"guanyu");
  //strcpy(msg1.buf,"guanyu");#include <string.h>
  msg2.mtype = 2;strcpy(msg2.buf,"zhangfei");
  msgsnd(msgid,&msg1,sizeof(msg1.buf),0);
  msgsnd(msgid,&msg2,sizeof(msg2.buf),0);
  printf("已发送2条\n");
}
/*
 root@test:/home/test/biaoc/C/uc/ucday10# gcc msgtypea.c -oa
 root@test:/home/test/biaoc/C/uc/ucday10# a
 已发送2条
 root@test:/home/test/biaoc/C/uc/ucday10# ipcs  -q

 --------- 消息队列 -----------
 键        msqid      拥有者  权限     已用字节数 消息      
 0x64011a25 0          root       666        512          2           

 root@test:/home/test/biaoc/C/uc/ucday10# a
 已发送2条
 root@test:/home/test/biaoc/C/uc/ucday10# ipcs  -q

 --------- 消息队列 -----------
 键        msqid      拥有者  权限     已用字节数 消息      
 0x64011a25 0          root       666        1024         4  
 */
