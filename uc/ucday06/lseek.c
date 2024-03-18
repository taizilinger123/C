#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  int fd = open("a.txt",O_RDWR);
  if(fd==-1) perror("open"),exit(-1);
  char ch;
  read(fd,&ch,1);printf("%c\n",ch);//a
  read(fd,&ch,1);printf("%c\n",ch);//b
  lseek(fd,3,SEEK_CUR);//从当前位置向后跳3
  read(fd,&ch,1);printf("%c\n",ch);//f
  lseek(fd,0,SEEK_SET);//回到文件开始
  write(fd,"1",1);//覆盖a
  lseek(fd,3,SEEK_SET);write(fd,"2",1);//d
  lseek(fd,2,SEEK_CUR);write(fd,"3",1);//g
  lseek(fd,-2,SEEK_CUR);write(fd,"4",1);//f
  lseek(fd,-3,SEEK_END);write(fd,"5",1);//S
  close(fd);
}
/*
 root@test:/home/test/biaoc/C/uc/ucday06# gcc lseek.c 
 root@test:/home/test/biaoc/C/uc/ucday06# a.out 
 1
 b
 4
 root@test:/home/test/biaoc/C/uc/ucday06# cat  a.txt 
 1bc2e43hijklmnopqr5t
 */
