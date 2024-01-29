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
  int fd=open("a.txt",O_RDONLY);
  if(fd==-1) perror("open"),exit(-1);
  struct emp em;
  read(fd,&em,sizeof(em));
  close(fd);
  printf("%d,%s,%lf\n",em.id,em.name,em.sal);
}
