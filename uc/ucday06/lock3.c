#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int fd = open("a.txt",O_RDWR);
	if(fd==-1) perror("open"),exit(-1);
	struct flock lock;
	lock.l_type = F_RDLCK;//必须先有读权限
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 20;
	lock.l_pid = -1;
	int res = fcntl(fd,F_SETLK,&lock);//加锁
	if(res==-1) printf("加锁失败\n");
	else printf("加锁成功,开始读文件\n");
	sleep(15);
	printf("成功读完文件\n");
	lock.l_type = F_UNLCK;//开始释放锁
	fcntl(fd,F_SETLK,&lock);
	sleep(10);
	printf("程序结束\n");
    close(fd);
}
