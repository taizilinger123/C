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
}
