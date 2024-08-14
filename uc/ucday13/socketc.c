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
   int len = read(sockfd,buf,100);
   printf("读到了%d字节，内容:%s\n",len,buf);
   close(sockfd);
}//练习：socketd.c实现，发一个hello过来
