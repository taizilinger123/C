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
 */
