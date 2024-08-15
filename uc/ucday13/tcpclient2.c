#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){
   int sockfd = socket(AF_INET,SOCK_STREAM,0);
   if(sockfd == -1) perror("socket"),exit(-1);
   struct sockaddr_in addr;//server端通信地址
   addr.sin_family = AF_INET;
   addr.sin_port = htons(2222);//本机转网络格式htons=host to network short
   addr.sin_addr.s_addr = inet_addr("10.0.1.128");//转换IP的函数，点分十进制转换为十六进制
   int res = connect(sockfd,(struct sockaddr*)&addr,sizeof(addr));
   if(res == -1) perror("connect"),exit(-1);
   printf("connect ok\n");
   char buf1[100] = {};//scanf() write()
   char buf2[100] = {};//read()
   while(1){
	  printf("请输入要说的话:\n");
	  scanf("%s",buf1);//输入
      write(sockfd,buf1,strlen(buf1));//发服务器
	  if(strcmp("bye",buf1)==0) break;
      read(sockfd,buf2,100);//读服务器回发数据
      printf("server:%s\n",buf2);
      memset(buf1,0,sizeof(buf1));//清空buf1
      memset(buf2,0,strlen(buf2));//清空buf2
   }
   close(sockfd);
}
