#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){//对比UC和标C函数 效果
  /*FILE* file = fopen("a.txt","w");
  if(file == NULL) perror("fopen"),exit(-1);
  int i;
  for(i=0;i<1000000;i++){
    fwrite(&i,4,1,file);
  }
  fclose(file);*/
  int fd=open("a.txt",O_RDWR|O_CREAT|O_TRUNC,0666);
  if(fd==-1) perror("open"),exit(-1);
  int i;
  for(i=0;i<1000000;i++){
     write(fd,&i,4);
  }
  close(fd);
}
/*
root@test:/home/test/biaoc/C/uc/ucday05# gcc testc.c  -oa 
root@test:/home/test/biaoc/C/uc/ucday05# ls
a      a.txt  filecopy.c  read.c     testc.c  writeemp.c
a.out  b.txt  open.c      reademp.c  write.c
root@test:/home/test/biaoc/C/uc/ucday05# a
root@test:/home/test/biaoc/C/uc/ucday05# ls -l 
总用量 3964
-rwxr-xr-x 1 root root    8872 2月   6 20:08 a
-rwxr-xr-x 1 root root    8920 1月  26 20:28 a.out
-rw-r--r-- 1 root root 4000000 2月   6 20:08 a.txt
-rw-r--r-- 1 root root      10 1月  23 22:12 b.txt
root@test:/home/test/biaoc/C/uc/ucday05# gcc testc.c -ob
root@test:/home/test/biaoc/C/uc/ucday05# b
root@test:/home/test/biaoc/C/uc/ucday05# ls -l 
总用量 3976
-rwxr-xr-x 1 root root    8872 2月   6 20:08 a
-rwxr-xr-x 1 root root    8920 1月  26 20:28 a.out
-rw-r--r-- 1 root root 4000000 2月   6 20:13 a.txt
-rwxr-xr-x 1 root root    8864 2月   6 20:13 b
-rw-r--r-- 1 root root      10 1月  23 22:12 b.txt
root@test:/home/test/biaoc/C/uc/ucday05# time a

real	0m0.039s
user	0m0.020s
sys	0m0.020s
root@test:/home/test/biaoc/C/uc/ucday05# time b

real	0m2.500s
user	0m0.204s
sys	0m2.295s

 */
