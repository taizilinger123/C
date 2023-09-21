#include <stdio.h>

int main(){
   printf("hello c\n");
}

/*
 [/home/test/biaoc/C/uc/ucday02]$gcc  hello.c 
 [/home/test/biaoc/C/uc/ucday02]$a.out
 hello c
 [/home/test/biaoc/C/uc/ucday02]$ls
 add.c  add.h  a.out  hello.c  pre.c  test.c
 [/home/test/biaoc/C/uc/ucday02]$gcc -static hello.c -ob.out //太大了
 [/home/test/biaoc/C/uc/ucday02]$ls
 add.c  add.h  a.out  b.out  hello.c  pre.c  test.c
 [/home/test/biaoc/C/uc/ucday02]$ls -l 
 总用量 924
 -rw-r--r-- 1 root root     93 9月  21 14:18 add.c
 -rw-r--r-- 1 root root    159 9月  21 14:11 add.h
 -rwxr-xr-x 1 root root   8600 9月  21 16:01 a.out
 -rwxr-xr-x 1 root root 912720 9月  21 16:02 b.out //太大了
 -rw-r--r-- 1 root root     58 9月  21 16:01 hello.c
 -rw-r--r-- 1 root root   3202 9月  21 14:03 pre.c
 -rw-r--r-- 1 root root   1540 9月  21 14:43 test.c
 [/home/test/biaoc/C/uc/ucday02]$vi b.out
 */
