#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(){
  key_t key = ftok(".",100);
  int msgid = msgget(key,0);
  if(msgid==-1) perror("msgget"),exit(-1);
  char buf[100] = {};
  int res = msgrcv(msgid,buf,sizeof(buf),0,0);
  if(res == -1) perror("msgrcv"),exit(-1);
  printf("收到%d字节的数据:%s\n",res,buf);
}

/*
 root@test:/home/test/biaoc/C/uc/ucday10# gcc msgb.c -ob
 root@test:/home/test/biaoc/C/uc/ucday10# b
 收到9字节的数据:hello msg
 root@test:/home/test/biaoc/C/uc/ucday10# b
 收到9字节的数据:hello msg
 root@test:/home/test/biaoc/C/uc/ucday10# b #会阻塞
#新开一个终端
root@test:/home/test/biaoc/C/uc/ucday10# pwd
/home/test/biaoc/C/uc/ucday10
root@test:/home/test/biaoc/C/uc/ucday10# a
发送成功
 root@test:/home/test/biaoc/C/uc/ucday10# b
 收到9字节的数据:hello msg
 root@test:/home/test/biaoc/C/uc/ucday10# ipcs -q

 --------- 消息队列 -----------
 键        msqid      拥有者  权限     已用字节数 消息      
 0x64011a25 0          root       666        0            0  
#再查消息变为0，数据都被取走了

 */
