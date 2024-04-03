#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
   int fd = open("a.txt",O_RDWR);
   if(fd==-1) perror("open"),exit(-1);
   struct flock lock;
   lock.l_type = F_RDLCK;
   lock.l_whence = SEEK_SET;
   lock.l_start = 10;
   lock.l_len = 30;
   lock.l_pid = -1;
   fcntl(fd,F_GETLK,&lock);
   if(lock.l_pid == -1) printf("可加读锁\n");
   else printf("不可加读锁\n");
   printf("%d,%d\n",lock.l_start,lock.l_len);
   printf("RD=%d,WR=%d,UN=%d\n",F_RDLCK,F_WRLCK,F_UNLCK);
   printf("type=%d\n",lock.l_type);
   struct flock wlock = {F_WRLCK,SEEK_SET,10,30,-1};
   fcntl(fd,F_GETLK,&wlock);
   if(wlock.l_pid == -1) printf("可加写锁\n");
   else printf("不可加写锁\n");
   printf("%d,%d\n",wlock.l_start,wlock.l_len);
   printf("type=%d\n",wlock.l_type);
   printf("l_pid=%d\n",wlock.l_pid);
}

/*
 root@test:/home/test/biaoc/C/uc/ucday06# gcc getlock.c  -ob
 getlock.c: In function ‘main’:
 getlock.c:18:11: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘__off_t {aka long int}’ [-Wformat=]
     printf("%d,%d\n",lock.l_start,lock.l_len);
	            ^
getlock.c:18:11: warning: format ‘%d’ expects argument of type ‘int’, but argument 3 has type ‘__off_t {aka long int}’ [-Wformat=]
root@test:/home/test/biaoc/C/uc/ucday06# a
加锁成功,开始读文件
成功读完文件
程序结束
再开一个终端：
abcderoot@test:/home/test/biaoc/C/uc/ucday06# a.out
可加读锁
10,30
RD=0,WR=1,UN=2
type=2   //RD=0类型为0变为2的UN类型了
###############################################

t@test:/home/test/biaoc/C/uc/ucday06# gcc getlock.c -ob
getlock.c: In function ‘main’:
getlock.c:18:11: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘__off_t {aka long int}’ [-Wformat=]
    printf("%d,%d\n",lock.l_start,lock.l_len);
	           ^
			   getlock.c:18:11: warning: format ‘%d’ expects argument of type ‘int’, but argument 3 has type ‘__off_t {aka long int}’ [-Wformat=]
			   getlock.c:25:11: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘__off_t {aka long int}’ [-Wformat=]
			       printf("%d,%d\n",wlock.l_start,wlock.l_len);
				              ^
							  getlock.c:25:11: warning: format ‘%d’ expects argument of type ‘int’, but argument 3 has type ‘__off_t {aka long int}’ [-Wformat=]
root@test:/home/test/biaoc/C/uc/ucday06# a
							  加锁成功,开始读文件
							  成功读完文件
							  程序结束
root@test:/home/test/biaoc/C/uc/ucday06# b
可加读锁
10,30
RD=0,WR=1,UN=2
type=2
不可加写锁
0,20
type=0
l_pid=12939
 */
