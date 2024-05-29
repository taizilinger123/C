#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  int fd = open("a.pipe",/*O_RDWR*/O_WRONLY);
  //O_RDWR管道文件不要用读写，会出问题，要用只读或者只写
  if(fd==-1) perror("open"),exit(-1);
  int i;
  for(i=0;i<100;i++){
    write(fd,&i,sizeof(i));
	printf("发送%d成功\n",i);
	usleep(100000);//0.1秒
  }
  close(fd);
}

/*
 root@test:/home/test/biaoc/C/uc/ucday10# gcc pipea.c -oa
 root@test:/home/test/biaoc/C/uc/ucday10# a
 发送0成功
 发送1成功
 发送2成功
 发送3成功
 */
