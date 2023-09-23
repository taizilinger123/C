#include <stdio.h>
#include <dlfcn.h>

int main(){
  void* handle = dlopen("./libmyku.so", RTLD_NOW);//打开库文件
  char* error = dlerror();
  if(error/*!=NULL*/){
     printf("打开失败\n");
	 return -1;
  }
  //double add2(double,double);//把add2换成(*f)就行了,为啥是(*f)因为不写(),double* f(double,double)这样子会认为是f返回的是double*这个指针
  //定义函数指针
  double (*f)(double,double);
  f = dlsym(handle,"add2");//获取函数add2
  error = dlerror();
  if(error){
     printf("获取函数失败\n");
	 return -1;
  }//link with -ldl
  double d = f(2.0,3.5);
  printf("d=%lf\n",d);
  dlclose(handle);
}

/*
 root@test:/home/test/biaoc/C/uc/ucday02# cd  sharelib/
 root@test:/home/test/biaoc/C/uc/ucday02/sharelib# ls
 add.c  add.h  add.o  a.out  dl.c  libmyku.so  test.c  test.o
 root@test:/home/test/biaoc/C/uc/ucday02/sharelib# gcc dl.c
 /tmp/cce1n3Fz.o：在函数‘main’中：
 dl.c:(.text+0x13)：对‘dlopen’未定义的引用
 dl.c:(.text+0x1c)：对‘dlerror’未定义的引用
 dl.c:(.text+0x4c)：对‘dlsym’未定义的引用
 dl.c:(.text+0x55)：对‘dlerror’未定义的引用
 dl.c:(.text+0xc7)：对‘dlclose’未定义的引用
collect2: error: ld returned 1 exit status
root@test:/home/test/biaoc/C/uc/ucday02/sharelib# gcc dl.c -ldl
root@test:/home/test/biaoc/C/uc/ucday02/sharelib# ls
add.c  add.h  add.o  a.out  dl.c  libmyku.so  test.c  test.o
root@test:/home/test/biaoc/C/uc/ucday02/sharelib# a.out
d=5.500000
root@test:/home/test/biaoc/C/uc/ucday02/sharelib# ldd a.out
	linux-vdso.so.1 =>  (0x00007fff6f8d4000)
		libdl.so.2 => /lib/x86_64-linux-gnu/libdl.so.2 (0x00007f1e45fb8000)
			libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f1e45bee000)
				/lib64/ld-linux-x86-64.so.2 (0x00007f1e461bc000)
 */
