#include <stdio.h>

#pragma  GCC dependency "hello.c"//确保当前文件比hello.c新
#pragma  GCC poison goto//禁止goto(下面代码)
#pragma  pack(1/*2*/)//针对结构体的对齐和补齐
int main(){
  //goto ok;
  printf("goto\n");
  ok:printf("main over\n");
  struct s{
     char c;
	 int i;
	 char ch;
  };
  printf("size=%d\n",sizeof(struct s));
}


/*
 root@test:/home/test/biaoc/C/uc/ucday02# vi  pre.c
 root@test:/home/test/biaoc/C/uc/ucday02# gcc  pre.c
 pre.c:3:25: fatal error: hello.c: 没有那个文件或目录
  #pragma  GCC dependency "hello.c"
                           ^
						   compilation terminated.
						   root@test:/home/test/biaoc/C/uc/ucday02# touch hello.c
						   root@test:/home/test/biaoc/C/uc/ucday02# 
						   root@test:/home/test/biaoc/C/uc/ucday02# 
						   root@test:/home/test/biaoc/C/uc/ucday02# ls
						   hello.c  pre.c
						   root@test:/home/test/biaoc/C/uc/ucday02# 
						   root@test:/home/test/biaoc/C/uc/ucday02# 
						   root@test:/home/test/biaoc/C/uc/ucday02# gcc  pre.c
						   pre.c:3:25: warning: current file is older than hello.c
						    #pragma  GCC dependency "hello.c"
							                         ^
													 root@test:/home/test/biaoc/C/uc/ucday02# ls
													 a.out  hello.c  pre.c
													 root@test:/home/test/biaoc/C/uc/ucday02# 
													 root@test:/home/test/biaoc/C/uc/ucday02# 
													 root@test:/home/test/biaoc/C/uc/ucday02# 
													 root@test:/home/test/biaoc/C/uc/ucday02# touch pre.c
													 root@test:/home/test/biaoc/C/uc/ucday02# 
													 root@test:/home/test/biaoc/C/uc/ucday02# 
													 root@test:/home/test/biaoc/C/uc/ucday02# ls
													 a.out  hello.c  pre.c
													 root@test:/home/test/biaoc/C/uc/ucday02# ls  -l 
													 总用量 16
													 -rwxr-xr-x 1 root root 8600 9月  21 10:57 a.out
													 -rw-r--r-- 1 root root    0 9月  21 10:57 hello.c
													 -rw-r--r-- 1 root root   93 9月  21 10:58 pre.c
													 root@test:/home/test/biaoc/C/uc/ucday02# gcc  pre.c
													 root@test:/home/test/biaoc/C/uc/ucday02# ./a.out
													 main over

root@test:/home/test/biaoc/C/uc/ucday02# vi pre.c
root@test:/home/test/biaoc/C/uc/ucday02# gcc  pre.c
pre.c: In function ‘main’:
pre.c:6:3: error: attempt to use poisoned "goto"
   goto ok;
      ^
	  """"""
 */
