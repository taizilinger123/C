//ATM的服务器端
#include "bank.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

//首先需要创建两个全局存储消息队列的id的变量
static int msgid1;
static int msgid2;
//写一个函数，用来创建两个消息队列，用到msg
void init(){
   //msgget函数，第一个参数是键值，bank.h
   //IPC_CREAT表示没有此消息队列则创建，
	//IPC_EXCL表示如果队列存在，则提示错误
	//0666是给此消息队列对象添加一些权限设置
	//创建消息队列1
	msgid1 = msgget(key1,IPC_CREAT|IPC_EXCL)
	if(msgid1 == -1){
	   perror("消息队列1创建失败"),exit(-1);
	}
	printf("消息队列1创建成功\n");
	//创建消息队列2
	msgid2 = msgget(key2,IPC_CREAT|IPC_EXCL)
	if(msgid2 == -1){
	   perror("消息队列2创建失败");
	   exit(-1);
	}
	printf("消息队列2创建成功\n");
}
//启动服务函数，用来创建子进程来执行用户不
void start(){
    printf("服务器正在启动..\n");
	sleep(2);
	//创建子进程
    pid_t open_pid = vfork();
	if(open_pid == -1){
	   perror("vfork failed");
	   exit(-1);
	}
	else if(open_pid == 0){//进入子进程
	   //printf("in child process\n");
	   execl("./open","open",NULL);//不再和父进程
	}
	else{
	   printf("正在等待客户端选择..\n");
	   waitpid(open_pid,0,0);//阻塞，等待子进程结束
	   //printf("in parent process\n");
	}
}

void sig_exit(){
  printf("服务器正在关闭..\n");
  sleep(2);
  if(msgctl(msgid1,IPC_RMID,NULL) == -1){
     perror("消息队列1删除失败\n");
	 exit(-1);
  }
  else{
     printf("消息队列1删除成功\n");
  }
  if(msgctl(msgid2,IPC_RMID,NULL) == -1){
     perror("消息队列2删除失败\n");
	 exit(-1);
  }
  else{
     printf("消息队列2删除成功\n");
  }
  printf("服务器成功关闭\n");
  exit(0);//直接结束程序
}
int main(){
  //我们退出服务器用一个信号处理函数来实现
  printf("退出服务器请按CTRL+C\n");//发送
  signal(SIGINT,sig_exit);//自定义信号处理函数
  //做好了善后工作，我们从头开始启动服务
  //创建消息队列
  init();
  //启动服务

}
