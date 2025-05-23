#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){
  int sockfd = socket(AF_INET,SOCK_STREAM,0);
  if(sockfd == -1) perror("socket"),exit(-1);
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(2222);
  addr.sin_addr.s_addr = inet_addr("10.0.1.128");
  int res = bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
  if(res==-1) perror("bind"),exit(-1);
  printf("bind ok\n");
  listen(sockfd,100);//4 监听
  struct sockaddr_in from;//用于存客户端地址
  socklen_t len = sizeof(from);//传入传出参数
  int fd = accept(sockfd,(struct sockaddr*)&from,&len);
  printf("%s连接了服务器\n",inet_ntoa(from.sin_addr));//十六 转 点分十进制
  char buf[100] = {};
  read(fd,buf,100);
  printf("%s\n",buf);
  write(fd,"welcome",7);
  close(fd); 
  close(sockfd);
}
