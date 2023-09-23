int add(int a, int b){
    return  a+b;
}
double add2(double a,double b){
    return  a+b;
}

/*
[/home/test/biaoc/C/uc/ucday02]$mkdir staticlib
[/home/test/biaoc/C/uc/ucday02]$ls
add.c  add.h  a.out  hello.c  pre.c  staticlib  test.c
[/home/test/biaoc/C/uc/ucday02]$cp add.*  staticlib/
[/home/test/biaoc/C/uc/ucday02]$ls
add.c  add.h  a.out  hello.c  pre.c  staticlib  test.c
[/home/test/biaoc/C/uc/ucday02]$cd staticlib/
[/home/test/biaoc/C/uc/ucday02/staticlib]$ls
add.c  add.h
[/home/test/biaoc/C/uc/ucday02/staticlib]$pwd
/home/test/biaoc/C/uc/ucday02/staticlib
[/home/test/biaoc/C/uc/ucday02/staticlib]$ls
add.c  add.h
[/home/test/biaoc/C/uc/ucday02/staticlib]$gcc -c add.c
[/home/test/biaoc/C/uc/ucday02/staticlib]$ls
add.c  add.h  add.o
[/home/test/biaoc/C/uc/ucday02/staticlib]$ar -r libmyku.a add.o
ar: 正在创建 libmyku.a
[/home/test/biaoc/C/uc/ucday02/staticlib]$ls
add.c  add.h  add.o  libmyku.a
##########################################################
[/home/test/biaoc/C/uc/ucday02/sharelib]$ls
add.c  add.h  test.c
[/home/test/biaoc/C/uc/ucday02/sharelib]$gcc -c -fpic  add.c 
[/home/test/biaoc/C/uc/ucday02/sharelib]$ls
add.c  add.h  add.o  test.c
[/home/test/biaoc/C/uc/ucday02/sharelib]$gcc -shared  add.o -o libmyku.so
[/home/test/biaoc/C/uc/ucday02/sharelib]$ls
add.c  add.h  add.o  libmyku.so  test.c
[/home/test/biaoc/C/uc/ucday02/sharelib]$gcc -c test.c
[/home/test/biaoc/C/uc/ucday02/sharelib]$ls
add.c  add.h  add.o  libmyku.so  test.c  test.o
[/home/test/biaoc/C/uc/ucday02/sharelib]$gcc  test.o  libmyku.so 
[/home/test/biaoc/C/uc/ucday02/sharelib]$ls
add.c  add.h  add.o  a.out  libmyku.so  test.c  test.o
[/home/test/biaoc/C/uc/ucday02/sharelib]$a.out
a.out: error while loading shared libraries: libmyku.so: cannot open shared object file: No such file or directory
[/home/test/biaoc/C/uc/ucday02/sharelib]$export LD_LIBRARY_PATH=.
[/home/test/biaoc/C/uc/ucday02/sharelib]$a.out
r1=5,r2=5.200000
[/home/test/biaoc/C/uc/ucday02/sharelib]$rm  a.out
[/home/test/biaoc/C/uc/ucday02/sharelib]$gcc  test.o -lmyku -L.
[/home/test/biaoc/C/uc/ucday02/sharelib]$ls
add.c  add.h  add.o  a.out  libmyku.so  test.c  test.o
[/home/test/biaoc/C/uc/ucday02/sharelib]$a.out
r1=5,r2=5.200000

 */
