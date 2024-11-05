#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>
#include <signal.h>
int sockfd;
void fa(int signo){
   close(sockfd);
   printf("服务器已经关闭\n");
   exit(0);
}
int main(){
   printf("按CTRL+C退出\n");
   signal(SIGINT,fa);
   sockfd = socket(AF_INET,SOCK_DGRAM,0);
   if(sockfd == -1) perror("socket"),exit(-1);
   struct sockaddr_in addr;
   addr.sin_family = AF_INET;
   addr.sin_port = htons(2222);
   addr.sin_addr.s_addr = INADDR_ANY;//本机IP
   int res = bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
   printf("bind ok\n");
   char buf[100] = {};
   struct sockaddr_in from;
   socklen_t len = sizeof(from);
   while(1){
     recvfrom(sockfd,buf,sizeof(buf),0,
	   (struct sockaddr*)&from,&len);
	 time_t cur_time;
     time(&cur_time);
	 struct tm* cur = localtime(&cur_time);
	 sprintf(buf,"%4d-%02d-%02d %02d:%02d:%02d",
	   cur->tm_year+1900,cur->tm_mon+1,
	   cur->tm_mday,cur->tm_hour,
	   cur->tm_min,cur->tm_sec);
	 sendto(sockfd,buf,sizeof(buf),0,
	    (struct sockaddr*)&from,len);
   }
}
/*
 root@test:/home/test/biaoc/C/uc/ucday14# gcc timeserver.c -oserver
 root@test:/home/test/biaoc/C/uc/ucday14# server
 bind ok

 */
