#include <stdio.h>
#include "add.h"

int main(){
   int r1 = add(2,3);
   double r2 = add2(3.1,2.1);
   printf("r1=%d,r2=%lf\n",r1,r2);
}

/*
 [/home/test/biaoc/C/uc/ucday02/staticlib]$ls
 add.c  add.h  add.o  libmyku.a  test.c  test.o
 [/home/test/biaoc/C/uc/ucday02/staticlib]$vi test.c
 [/home/test/biaoc/C/uc/ucday02/staticlib]$gcc -c  test.c
 [/home/test/biaoc/C/uc/ucday02/staticlib]$ls
 add.c  add.h  add.o  libmyku.a  test.c  test.o
 [/home/test/biaoc/C/uc/ucday02/staticlib]$gcc  test.o  libmyku.a 
 [/home/test/biaoc/C/uc/ucday02/staticlib]$ls
 add.c  add.h  add.o  a.out  libmyku.a  test.c  test.o
 [/home/test/biaoc/C/uc/ucday02/staticlib]$a.out
 r1=5,r2=5.200000
 [/home/test/biaoc/C/uc/ucday02/staticlib]$rm a.out
 [/home/test/biaoc/C/uc/ucday02/staticlib]$gcc test.o -lmyku -L.
 [/home/test/biaoc/C/uc/ucday02/staticlib]$ls
 add.c  add.h  add.o  a.out  libmyku.a  test.c  test.o
 [/home/test/biaoc/C/uc/ucday02/staticlib]$a.out
 r1=5,r2=5.200000
 [/home/test/biaoc/C/uc/ucday02/staticlib]$rm a.out
 [/home/test/biaoc/C/uc/ucday02/staticlib]$ls
 add.c  add.h  add.o  libmyku.a  test.c  test.o
 [/home/test/biaoc/C/uc/ucday02/staticlib]$export LIBRARY_PATH=.
 [/home/test/biaoc/C/uc/ucday02/staticlib]$gcc test.o -lmyku
 [/home/test/biaoc/C/uc/ucday02/staticlib]$ls
 add.c  add.h  add.o  a.out  libmyku.a  test.c  test.o
 [/home/test/biaoc/C/uc/ucday02/staticlib]$a.out
 r1=5,r2=5.200000
 
 */
