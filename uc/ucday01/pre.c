#include <stdio.h>

#define VERSION 2
#if(VERSION<3)
  #error "版本太低"
#elif(VERSION>3)
  #warning "版本太高"
#endif
int main(){
   return 0;
}

/*
 root@test:/home/test/biaoc/C/uc/ucday01# vi pre.c
 root@test:/home/test/biaoc/C/uc/ucday01# gcc  pre.c 
 pre.c:7:4: warning: #warning "版本太高" [-Wcpp]
    #warning "版本太高"
	    ^
		root@test:/home/test/biaoc/C/uc/ucday01# ls
		a.out  hello.c  hello.i  hello.o  hello.s  pre.c
			   root@test:/home/test/biaoc/C/uc/ucday01# rm  -rf  a.out 
			   root@test:/home/test/biaoc/C/uc/ucday01# vi pre.c
			   root@test:/home/test/biaoc/C/uc/ucday01# gcc  pre.c 
			   pre.c:5:4: error: #error "版本太低"
			      #error "版本太低"
				      ^
					  root@test:/home/test/biaoc/C/uc/ucday01# ls
					  hello.c  hello.i  hello.o  hello.s  pre.c
 */
