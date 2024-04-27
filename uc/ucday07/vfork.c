#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
   pid_t pid = vfork();//fork();
   if(pid==0){//vfork()确保子进程先运行
     sleep(5);
	 printf("child over\n");
	 exit(0);//子进程最好用exit(0)确保退出
   }
   printf("father over\n");
}

/*
 root@test:/home/test/biaoc/C/uc/ucday07# gcc  vfork.c
 root@test:/home/test/biaoc/C/uc/ucday07# a.out
 father over
 root@test:/home/test/biaoc/C/uc/ucday07# child over

 root@test:/home/test/biaoc/C/uc/ucday07# vi vfork.c 
 root@test:/home/test/biaoc/C/uc/ucday07# gcc  vfork.c 
 root@test:/home/test/biaoc/C/uc/ucday07# a.out
 child over
 father over
 a.out: cxa_atexit.c:100: __new_exitfn: Assertion `l != NULL' failed.
 已放弃 (核心已转储)
 root@test:/home/test/biaoc/C/uc/ucday07# vi vfork.c 
 root@test:/home/test/biaoc/C/uc/ucday07# gcc  vfork.c 
 root@test:/home/test/biaoc/C/uc/ucday07# a.out 
 child over
 father over
 */
