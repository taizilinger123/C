#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>

int main(){
   int sockfd = socket(AF_UNIX,SOCK_DGRAM,0);//1 创建套接字 
   if(sockfd==-1) perror("socket"),exit(-1);
   struct sockaddr_un addr;//2  准备通信地址
   addr.sun_family = AF_UNIX;//与socket一致
   strcpy(addr.sun_path,"a.sock");
   int res = connect(sockfd,(struct sockaddr*)&addr,sizeof(addr));//3 绑定
   if(res==-1) perror("connect"),exit(-1);
   printf("connect ok!\n");
   write(sockfd,"hello",strlen("hello"));
   close(sockfd);//5 关闭
}

/*
 gcc socketb.c -ob
 b
 */
