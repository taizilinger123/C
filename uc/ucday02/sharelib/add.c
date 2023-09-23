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
[/home/test/biaoc/C/uc/ucday02/sharelib]$ls
add.c  add.h  add.o  a.out  libmyku.so  test.c  test.o
[/home/test/biaoc/C/uc/ucday02/sharelib]$ldd libmyku.so 
	linux-vdso.so.1 =>  (0x00007ffc02160000)
	libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fc624625000)
	/lib64/ld-linux-x86-64.so.2 (0x00007fc624bf1000)
[/home/test/biaoc/C/uc/ucday02/sharelib]$ldd  a.out
	linux-vdso.so.1 =>  (0x00007ffda8d48000)
	libmyku.so => ./libmyku.so (0x00007f49d7be3000)
	libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f49d7819000)
	/lib64/ld-linux-x86-64.so.2 (0x00007f49d7de5000)
root@test:/home/test/biaoc/C/uc/ucday02/sharelib# ls
add.c  add.h  add.o  a.out  libmyku.so  test.c  test.o
root@test:/home/test/biaoc/C/uc/ucday02/sharelib# source  /etc/profile
[/home/test/biaoc/C/uc/ucday02/sharelib]$ls
add.c  add.h  add.o  a.out  libmyku.so  test.c  test.o
[/home/test/biaoc/C/uc/ucday02/sharelib]$pwd
/home/test/biaoc/C/uc/ucday02/sharelib
[/home/test/biaoc/C/uc/ucday02/sharelib]$ls
add.c  add.h  add.o  a.out  libmyku.so  test.c  test.o
[/home/test/biaoc/C/uc/ucday02/sharelib]$a.out
a.out: error while loading shared libraries: libmyku.so: cannot open shared object file: No such file or directory
[/home/test/biaoc/C/uc/ucday02/sharelib]$ldd  a.out
	linux-vdso.so.1 =>  (0x00007fff1714d000)
		libmyku.so => not found
			libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f4fbcaaa000)
		/lib64/ld-linux-x86-64.so.2 (0x00007f4fbce74000)
	[/home/test/biaoc/C/uc/ucday02/sharelib]$a.out
	a.out: error while loading shared libraries: libmyku.so: cannot open shared object file: No such file or directory
	[/home/test/biaoc/C/uc/ucday02/sharelib]$export  LD_LIBRARY_PATH=.
	[/home/test/biaoc/C/uc/ucday02/sharelib]$ldd  a.out
		linux-vdso.so.1 =>  (0x00007ffdc1714000)
		libmyku.so => ./libmyku.so (0x00007f8d207bc000)
		libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f8d203f2000)
		/lib64/ld-linux-x86-64.so.2 (0x00007f8d209be000)
	[/home/test/biaoc/C/uc/ucday02/sharelib]$a.out
	r1=5,r2=5.200000

 */
