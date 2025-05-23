#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>

int sockfd;
void fa(int signo){
   printf("关闭服务器\n");
   close(sockfd);
   exit(0);
}
int main(){
  printf("按ctrl+C退出服务器\n");
  signal(SIGINT,fa);
  sockfd = socket(AF_INET,SOCK_STREAM,0);
  if(sockfd == -1) perror("socket"),exit(-1);
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(2222);
  addr.sin_addr.s_addr = inet_addr("10.0.1.128");
  //解决地址已经使用问题的代码
  int reuse = 1;
  setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(reuse));
  int res = bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
  if(res==-1) perror("bind"),exit(-1);
  printf("bind ok\n");
  listen(sockfd,100);//4 监听
  while(1){
      struct sockaddr_in from;//用于存客户端地址
      socklen_t len = sizeof(from);//传入传出参数
      int fd = accept(sockfd,(struct sockaddr*)&from,&len);
      printf("%s连接了服务器\n",inet_ntoa(from.sin_addr));//十六 转 点分十进制
	  pid_t pid = fork();
	  if(pid == 0){
         char buf[100] = {};
	     while(1){
            read(fd,buf,100);
            printf("client:%s\n",buf);
		    if(strcmp("bye",buf)==0) break;
            write(fd,buf,strlen(buf));
		    memset(buf,0,sizeof(buf));
	     }
         close(fd); 
		 exit(0);
      }
	  close(fd);
  }
  //close(sockfd);//在这里执行不到
}//练习: 用信号2实现关闭sockfd
/*
 root@test:/home/test/biaoc/C/uc/ucday13# gcc tcpserver2.c  -oserver
 root@test:/home/test/biaoc/C/uc/ucday13# pwd
 /home/test/biaoc/C/uc/ucday13
 root@test:/home/test/biaoc/C/uc/ucday13# server
 按ctrl+C退出服务器
 bind ok
 10.0.1.128连接了服务器
client:nihao
client:nihenhao
10.0.1.128连接了服务器
client:wohenniu
client:wojiushihenniu
client:niniu
client:woniu
client:bye
client:bye
^C关闭服务器
#第二个终端
root@test:/home/test/biaoc/C/uc/ucday13# client
connect ok
请输入要说的话:
nihao
server:nihao
请输入要说的话:
nihenhao
server:nihenhao
请输入要说的话:
niniu
server:niniu
请输入要说的话:
bye
#第三个终端
root@test:/home/test/biaoc/C/uc/ucday13# client
connect ok
请输入要说的话:
wohenniu
server:wohenniu
请输入要说的话:
wojiushihenniu
server:wojiushihenniu
请输入要说的话:
woniu
server:woniu
请输入要说的话:
bye

 */
