#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  int fd=open("a.txt",O_RDWR|O_CREAT|O_TRUNC,0666);
  if(fd==-1) perror("open"),exit(-1);
  int res = write(fd,"hello unix",10);
  if(res==-1) perror("write"),exit(-1);
  printf("写入%d个字节成功\n",res);
  close(fd);
}
