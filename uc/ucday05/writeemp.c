#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

struct emp{
  int id;
  char name[20];
  double sal;
};
int main(){
  int fd=open("a.txt",O_RDWR|O_CREAT|O_TRUNC,0666);
  if(fd==-1) perror("open"),exit(-1);
  struct emp em = {1,"zhangfei",12000.0};
  write(fd,&em,sizeof(em));
  close(fd);
}
