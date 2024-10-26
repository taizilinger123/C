#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){
   int sockfd = socket(AF_INET,SOCK_DGRAM,0);
   if(sockfd == -1) perror("socket"),exit(-1);
   struct sockaddr_in addr;//server端通信地址
   addr.sin_family = AF_INET;
   addr.sin_port = htons(2222);//本机转网络格式htons=host to network short
   addr.sin_addr.s_addr = inet_addr("10.0.1.128");//转换IP的函数，点分十进制转换为十六进制
   sendto(sockfd,"hello",5,0,(struct sockaddr*)&addr,sizeof(addr));
   char buf[100] = {};
   read(sockfd,buf,100);
   printf("%s\n",buf);
   close(sockfd);
}
