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
  int msgid = msgget(key,0);
  if(msgid == -1) perror("msgget"),exit(-1);
  struct MSG msg;
  int res = msgrcv(msgid,&msg,sizeof(msg.buf),-2/*2*/,0);
  if(res==-1) perror("msgrcv"),exit(-1);
  printf("接收%d字节数据:%s\n",res,msg.buf);
}
/*
 root@test:/home/test/biaoc/C/uc/ucday10# gcc msgtypeb.c -ob
 root@test:/home/test/biaoc/C/uc/ucday10# b
 接收256字节数据:zhangfei
 root@test:/home/test/biaoc/C/uc/ucday10# b
 接收256字节数据:zhangfei
 root@test:/home/test/biaoc/C/uc/ucday10# b
 ^C
 #新开一个终端执行
 root@test:/home/test/biaoc/C/uc/ucday10# a
 已发送2条
 root@test:/home/test/biaoc/C/uc/ucday10# b
 接收256字节数据:zhangfei
 root@test:/home/test/biaoc/C/uc/ucday10# ipcs  -q

 --------- 消息队列 -----------
 键        msqid      拥有者  权限     已用字节数 消息      
 0x64011a25 0          root       666        768          3 
#############################################################
root@test:/home/test/biaoc/C/uc/ucday10# gcc msgtypeb.c  -ob
root@test:/home/test/biaoc/C/uc/ucday10# a
已发送2条
root@test:/home/test/biaoc/C/uc/ucday10# a
已发送2条
root@test:/home/test/biaoc/C/uc/ucday10# ipcs -q

--------- 消息队列 -----------
键        msqid      拥有者  权限     已用字节数 消息      
0x64011a25 0          root       666        1792         7           

root@test:/home/test/biaoc/C/uc/ucday10# b
接收256字节数据:guanyu
root@test:/home/test/biaoc/C/uc/ucday10# b
接收256字节数据:guanyu
root@test:/home/test/biaoc/C/uc/ucday10# b
接收256字节数据:guanyu
root@test:/home/test/biaoc/C/uc/ucday10# b
接收256字节数据:guanyu
root@test:/home/test/biaoc/C/uc/ucday10# b
接收256字节数据:guanyu
root@test:/home/test/biaoc/C/uc/ucday10# b
接收256字节数据:zhangfei
root@test:/home/test/biaoc/C/uc/ucday10# b
接收256字节数据:zhangfei

 */
