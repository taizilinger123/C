#include <stdio.h>

int main() {
  
	printf("hello c\n");
    
}


/*
 root@test:/home/test/biaoc/C/uc/ucday01# ls
 hello.c
 root@test:/home/test/biaoc/C/uc/ucday01# gcc -E hello.c -ohello.i      
 root@test:/home/test/biaoc/C/uc/ucday01# ls
 hello.c  hello.i
 root@test:/home/test/biaoc/C/uc/ucday01# vi  hello.i
 root@test:/home/test/biaoc/C/uc/ucday01# gcc  -S  hello.i
 root@test:/home/test/biaoc/C/uc/ucday01# ls
 hello.c  hello.i  hello.s
 root@test:/home/test/biaoc/C/uc/ucday01# gcc -c hello.i
 root@test:/home/test/biaoc/C/uc/ucday01# ls
 hello.c  hello.i  hello.o  hello.s
 root@test:/home/test/biaoc/C/uc/ucday01# rm  -rf  hello.o
 root@test:/home/test/biaoc/C/uc/ucday01# ls
 hello.c  hello.i  hello.s
 root@test:/home/test/biaoc/C/uc/ucday01# gcc -c hello.s
 root@test:/home/test/biaoc/C/uc/ucday01# ls
 hello.c  hello.i  hello.o  hello.s
 root@test:/home/test/biaoc/C/uc/ucday01# gcc hello.o
 root@test:/home/test/biaoc/C/uc/ucday01# a.out
 a.out：未找到命令
 root@test:/home/test/biaoc/C/uc/ucday01# ./a.out
 hello c




 */
