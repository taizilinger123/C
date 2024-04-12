#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(){
   struct  stat s = {};
   int res = stat("a.txt",&s);//文件状态-> S
   if(res==-1)perror("stat"),exit(-1);
   printf("inode=%d\n",s.st_ino);
   printf("mode=%o\n",s.st_mode);//类型+权限
   printf("nlink=%d\n",s.st_nlink);//硬连接数
   printf("size=%d\n",s.st_size);//文件大小
   printf("time=%s\n",ctime(&s.st_mtime));
   printf("权限:%o\n",s.st_mode & 07777);
   if(S_ISREG(s.st_mode)) printf("普通文件\n");
   if(S_ISDIR(s.st_mode)) printf("目录\n");
}

/*
 root@test:/home/test/biaoc/C/uc/ucday06# gcc stat.c
 root@test:/home/test/biaoc/C/uc/ucday06# a.out
 inode=3280708
 mode=100644
 nlink=1
 size=5
 段错误 (核心已转储)
root@test:/home/test/biaoc/C/uc/ucday06# ls  -li  a.txt 
3280708 -rw-r--r-- 1 root root 5 4月   1 22:18 a.txt
 */
