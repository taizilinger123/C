#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int fd = open("a.txt",O_RDWR/*WRONLY*/);
	if(fd==-1) perror("open"),exit(-1);
	struct flock lock;
	lock.l_type = F_RDLCK;//必须先有读权限
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 20;
	lock.l_pid = -1;
	int res = fcntl(fd,F_SETLK,&lock);//加锁
	if(res==-1) printf("加锁失败\n");
	else printf("加锁成功\n");
	sleep(20);
    close(fd);//进程结束自动释放锁
}

/*
 root@test:/home/test/biaoc/C/uc/ucday06# gcc lock.c -oa
 root@test:/home/test/biaoc/C/uc/ucday06# cp lock.c lock2.c
 root@test:/home/test/biaoc/C/uc/ucday06# vi lock2.c
 root@test:/home/test/biaoc/C/uc/ucday06# gcc lock2.c -ob
 root@test:/home/test/biaoc/C/uc/ucday06# a
 加锁成功
 root@test:/home/test/biaoc/C/uc/ucday06# b
 加锁成功
 //a和b都是读锁加锁都成功了
 */
