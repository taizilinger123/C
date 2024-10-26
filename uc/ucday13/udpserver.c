#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){
   int sockfd = socket(AF_INET,SOCK_DGRAM,0);
   if(sockfd == -1) perror("socket"),exit(-1);
   struct sockaddr_in addr;
   addr.sin_family = AF_INET;
   addr.sin_port = htons(2222);//本机转网络格式htons=host to network short
   addr.sin_addr.s_addr = inet_addr("10.0.1.128");//转换IP的函数，点分十进制转换为十六进制
   int res = bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
   if(res == -1) perror("bind"),exit(-1);
   printf("bind ok\n");
   char buf[100] = {};
   struct sockaddr_in from;
   socklen_t  len = sizeof(from);
   int size = recvfrom(sockfd,buf,100,0,(struct sockaddr*)&from,&len);
   printf("读到了%d字节，内容:%s\n",len,buf);
   sendto(sockfd,"welcome",7,0,(struct sockaddr*)&from,len);
   close(sockfd);
}

/*
 root@test:/home/test/biaoc/C/uc/ucday13# gcc udpserver.c -oserver
 udpserver.c: In function ‘main’:
 udpserver.c:24:4: warning: implicit declaration of function ‘close’ [-Wimplicit-function-declaration]
     close(sockfd);
	     ^
		 root@test:/home/test/biaoc/C/uc/ucday13# server
		 bind ok
		 读到了16字节，内容:hello
//再开一个终端
root@test:/home/test/biaoc/C/uc/ucday13# client
welcome

 */
