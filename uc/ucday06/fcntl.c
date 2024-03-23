#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
   int fd=open("a.txt",O_RDWR|O_CREAT|O_TRUNC,0666);
   if(fd==-1) perror("open"),exit(-1);
   int fd2 = fcntl(fd,F_DUPFD,5);
   int fd3 = fcntl(fd,F_DUPFD,5);//大于等于5
   printf("fd2=%d,fd3=%d\n",fd2,fd3);
}
