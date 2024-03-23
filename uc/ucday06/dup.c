#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
   int fd = open("a.txt",O_RDWR);
   if(fd==-1) perror("open"),exit(-1);
   int fd2 = dup(fd);//复制了描述符但不复制文件表
   printf("fd=%d,fd2=%d\n",fd,fd2);
   write(fd,"A",1);
   write(fd2,"B",1);
   int fd3 = dup2(fd,100);
   printf("fd3=%d\n",fd3);
   
   int fd4 = open("b.txt",O_RDWR|O_CREAT,0666);
   printf("fd4=%d\n",fd4);//5
   int fd5 = dup2(fd,5);//5被使用，原先的被关闭
   printf("fd5=%d\n",5);
   write(fd4,"HEHE",4);//write(5,"HEHE",4);
}
