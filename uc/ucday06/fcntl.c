#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
   int fd=open("a.txt",O_RDWR|O_CREAT|O_APPEND,0666);
   if(fd==-1) perror("open"),exit(-1);
   int fd2 = fcntl(fd,F_DUPFD,5);
   int fd3 = fcntl(fd,F_DUPFD,5);//大于等于5
   printf("fd2=%d,fd3=%d\n",fd2,fd3);//5 6
   //获取/设置文件状态F_GETFL  F_SETFL
   int flag = fcntl(fd,F_GETFL);//没有创建表
   printf("flag=%d\n",flag);
   //O_APPEND的文件描述符的大小是1024字节
   //O_RDWR的文件描述符的大小应该是2个字节，这里是32770
}
