#include <stdio.h>

int main() {
  
	printf("hello c\n");
    return 0;    
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
 root@test:/home/test/biaoc/C/uc/ucday01# gcc  hello.c -Wall

 gcc的常见选项：
 -v  查看gcc编译器的版本
 -c  只编译不连接
 -E  只做预处理
 -S  汇编
 -o  改变目标文件名
													            什么选择都没有  编译并且连接
C程序中的文件名后缀
.a  静态对象库
.c  需要预处理的c语言源代码
.h  c语言源代码头文件
.i  不需要预处理的c语言源代码
.o  目标文件
.s  汇编语言代码
.so 共享对象库
 */
