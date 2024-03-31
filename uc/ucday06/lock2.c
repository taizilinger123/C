#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int fd = open("a.txt",O_RDWR);
	if(fd==-1) perror("open"),exit(-1);
	struct flock lock;
	lock.l_type = F_WRLCK;//F_RDLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 20;
	lock.l_pid = -1;
	int res = fcntl(fd,F_SETLK,&lock);//加锁
	if(res==-1) printf("加锁失败\n");
	else printf("加锁成功\n");
    close(fd);
}

/*
 root@test:/home/test/biaoc/C/uc/ucday06# gcc lock2.c -ob
 root@test:/home/test/biaoc/C/uc/ucday06# a
 加锁成功
 root@test:/home/test/biaoc/C/uc/ucday06# b
 加锁失败
 root@test:/home/test/biaoc/C/uc/ucday06# b
 加锁成功  //等a的锁时间结束b就加锁成功

 */
