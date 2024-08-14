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
   int res = bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));//3 绑定
   if(res==-1) perror("bind"),exit(-1);
   printf("bind ok!\n");
   char buf[100] = {};//4 读写数据
   int len = read(sockfd,buf,sizeof(buf));
   printf("读到%d字节，内容:%s\n",len,buf);
   close(sockfd);//5 关闭
}//练习：把socketb.c写一下，改bind和读写数据
//写完 运行，完成数据的交互
/* 
 gcc socketb.c -oa
 a
 */
