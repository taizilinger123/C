#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>
#include <signal.h>
int main(){
   int sockfd = socket(AF_INET,SOCK_DGRAM,0);
   if(sockfd == -1) perror("socket"),exit(-1);
   struct sockaddr_in addr;
   addr.sin_family = AF_INET;
   addr.sin_port = htons(2222);
   addr.sin_addr.s_addr = inet_addr("10.0.1.128");
   char buf[100] = {};
   sendto(sockfd,"hello",5,0,
	    (struct sockaddr*)&addr,sizeof(addr));
   read(sockfd,buf,sizeof(buf));
   printf("time=%s\n",buf);
   close(sockfd);
}
/*
 root@test:/home/test/biaoc/C/uc/ucday14# gcc timeclient.c -oclient
 root@test:/home/test/biaoc/C/uc/ucday14# client
 time=2024-11-04 23:46:12

 */
