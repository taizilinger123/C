#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "bank.h"
int main(){
   int msgid1 = msgget(key1,0);
   if(msgid1 == -1){
       perror("获取消息队列1失败");
	   printf("服务器启动失败");
	   exit(-1);
   }
   int msgid2 = msgget(key2,0);
   if(msgid2 == -1){
       perror("获取消息队列2失败");
	   printf("服务器启动失败");
	   exit(-1);
   }
   //获取到消息队列之后，开始接受消息
   while(1){
       struct Msg msg;//存储消息信息的结构体
	   struct Account accMove,accResult;//存储账号
	   //首先从客户那里收取消息队列1的信息 msgr
	   if(msgrcv(msgid1,&msg,sizeof(msg.acc),0,0))
		   break;
   }
   //如果接受到了消息，根据消息的不同类型进行
   if(msg.mtype == M_OPEN){//如果类型是开户
      int  id = generator_id();
	  accMove = msg.acc;
	  accMove.id = id;
   }
}
