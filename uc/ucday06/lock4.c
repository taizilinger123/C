#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int fd = open("a.txt",O_RDWR);
	if(fd==-1) perror("open"),exit(-1);
	struct flock rlock;
	rlock.l_type = F_RDLCK;
	rlock.l_whence = SEEK_SET;
	rlock.l_start = 0;
	rlock.l_len = 20;
	rlock.l_pid = -1;
	int res = fcntl(fd,F_SETLK,&rlock);//加锁
	if(res==-1) printf("加读锁失败\n");
	else printf("加读锁成功\n");
	struct flock wlock;
	wlock.l_type = F_WRLCK;
	wlock.l_whence = SEEK_SET;
	wlock.l_start = 0;
	wlock.l_len = 20;
	wlock.l_pid = -1;
	res = fcntl(fd,F_SETLKW/*F_SETLK*/,&wlock);//加锁
	if(res==-1) printf("加写锁失败\n");
	else printf("加写锁成功\n");
    close(fd);
}

/*
 root@test:/home/test/biaoc/C/uc/ucday06# vi lock3.c
 root@test:/home/test/biaoc/C/uc/ucday06# gcc lock3.c -oa
 root@test:/home/test/biaoc/C/uc/ucday06# cp lock2.c lock4.c
 root@test:/home/test/biaoc/C/uc/ucday06# vi lock4.c 
 root@test:/home/test/biaoc/C/uc/ucday06# gcc lock4.c -ob
 root@test:/home/test/biaoc/C/uc/ucday06# a
 加锁成功,开始读文件
 成功读完文件//a读完b加写锁成功
 程序结束
 root@test:/home/test/biaoc/C/uc/ucday06# b
 加读锁成功
 加写锁失败
 root@test:/home/test/biaoc/C/uc/ucday06# b
 加读锁成功
 加写锁成功  //当a成功读完文件的时候b这里加写锁成功
 */
