#include <stdio.h>

int a = 1;//gcc  test.c -oa
//int a = 3; //gcc  test.c -ob
int main(){
   printf("a=%d,%p\n",a,&a);
   sleep(5);
}

/*
root@test:/home/test/biaoc/C/uc/ucday03# gcc  test.c -oa
test.c: In function ‘main’:
test.c:7:4: warning: implicit declaration of function ‘sleep’ [-Wimplicit-function-declaration]
    sleep(5);
	    ^
root@test:/home/test/biaoc/C/uc/ucday03# a
a=1,0x601040
root@test:/home/test/biaoc/C/uc/ucday03# gcc  test.c -ob
test.c: In function ‘main’:
test.c:7:4: warning: implicit declaration of function ‘sleep’ [-Wimplicit-function-declaration]
    sleep(5);
	    ^
root@test:/home/test/biaoc/C/uc/ucday03# b
a=3,0x601040

 */
