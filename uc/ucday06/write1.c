#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
   int fd = open("a.txt",O_RDWR);
   /*
   write(fd,"a",1);
   sleep(10);
   write(fd,"b",1);
   sleep(5);
   write(fd,"c",1);
   */
   write(fd,"1",1);
   sleep(10);
   write(fd,"2",1);
   sleep(5);
   write(fd,"3",1);
   close(fd);
}


/*
 root@test:/home/test/biaoc/C/uc/ucday06# gcc  write1.c -oa
 root@test:/home/test/biaoc/C/uc/ucday06# gcc  write1.c -ob
 root@test:/home/test/biaoc/C/uc/ucday06# cat /dev/null > a.txt 
 root@test:/home/test/biaoc/C/uc/ucday06# a
 root@test:/home/test/biaoc/C/uc/ucday06# b
 root@test:/home/test/biaoc/C/uc/ucday06# cat a.txt 
 123 

 */
