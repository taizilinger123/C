#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  int fd = open("a.pipe",O_RDONLY);
  if(fd==-1) perror("open"),exit(-1);
  for(;;){
	int x;
    int res = read(fd,&x,sizeof(x));
	if(res<=0) break;
	printf("%d\n",x);
  }
  close(fd);
}
/*
 root@test:/home/test/biaoc/C/uc/ucday10# gcc pipea.c -oa
 root@test:/home/test/biaoc/C/uc/ucday10# a \\发送
 \\再新开一个终端
 cd /home/test/biaoc/C/uc/ucday10
 root@test:/home/test/biaoc/C/uc/ucday10# gcc pipeb.c -ob
 root@test:/home/test/biaoc/C/uc/ucday10# b \\接受
 */
