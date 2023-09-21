#include <stdio.h>
#include <add.h>

int main(){
   int r1 = add(2,3);
   double r2 = add2(2.0,3.0);
   printf("r1=%d,r2=%lf\n",r1,r2);
}

/*
 [/home/test/biaoc/C/uc/ucday02]$gcc  test.c 
 /tmp/ccR0A8Aq.o：在函数‘main’中：
 test.c:(.text+0x13)：对‘add’未定义的引用
 test.c:(.text+0x3a)：对‘add2’未定义的引用
collect2: error: ld returned 1 exit status
[/home/test/biaoc/C/uc/ucday02]$gcc  test.c add.c
[/home/test/biaoc/C/uc/ucday02]$a.out
r1=5,r2=5.000000
[/home/test/biaoc/C/uc/ucday02]$vi  test.c
[/home/test/biaoc/C/uc/ucday02]$gcc  test.c add.c
[/home/test/biaoc/C/uc/ucday02]$echo $CPATH
:.
[/home/test/biaoc/C/uc/ucday02]$tail  -n 4  /etc/profile
export CPATH=$CPATH:.
export LIBRARY_PATH=$LIBRARY_PATH:.
export PS1='[\w]$'
export PATH=$PATH:.
[/home/test/biaoc/C/uc/ucday02]$export  CPATH=.
[/home/test/biaoc/C/uc/ucday02]$cat  test.c
#include <stdio.h>
#include <add.h>  //export CPATH=.

int main(){
    int r1 = add(2,3);
    double r2 = add2(2.0,3.0);
    printf("r1=%d,r2=%lf\n",r1,r2);
}
[/home/test/biaoc/C/uc/ucday02]$gcc  test.c add.c
[/home/test/biaoc/C/uc/ucday02]$tail -n 4 /etc/profile
#export CPATH=$CPATH:.
export LIBRARY_PATH=$LIBRARY_PATH:.
export PS1='[\w]$'
export PATH=$PATH:.
[/home/test/biaoc/C/uc/ucday02]$source /etc/profile
[/home/test/biaoc/C/uc/ucday02]$gcc  test.c  add.c
test.c:2:17: fatal error: add.h: 没有那个文件或目录
compilation terminated.
[/home/test/biaoc/C/uc/ucday02]$gcc  test.c  add.c -I.
[/home/test/biaoc/C/uc/ucday02]$a.out
r1=5,r2=5.000000
 */
