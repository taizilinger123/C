#include <iostream>
using namespace std;
class A{
   int *parr;
   public:
   //:parr(new int[5])这种主要在const和引用&类型参数用
   //构造函数
   A():parr(new int[5]){
	  //parr=new int[5];
      cout<<"A()"<<parr<<endl;
   }
   //析构函数
   ~A(){
      cout<<"~A()"<<endl;
	  delete[] parr;
	  //空指针能解决析构函数重复释放的问题
	  parr=NULL;
   }
};
void testA(){
   A  a;
   //重复释放内存
   a.~A();
   /*A  *b=new  A();
   delete b;*/
}
int main(){
   testA();
}

/*
 root@test:/home/test/biaoc/C/C++/day04# ./a.out
 A()
 ~A()
 ~A()
 *** Error in `./a.out': double free or corruption (fasttop): 0x0000000002258c20 ***
 ======= Backtrace: =========
 /lib/x86_64-linux-gnu/libc.so.6(+0x777f5)[0x7fa6801007f5]
 /lib/x86_64-linux-gnu/libc.so.6(+0x8038a)[0x7fa68010938a]
 /lib/x86_64-linux-gnu/libc.so.6(cfree+0x4c)[0x7fa68010d58c]
 ./a.out[0x400ba1]
 ./a.out[0x400a82]
 ./a.out[0x400ac3]
 /lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xf0)[0x7fa6800a9840]
 ./a.out[0x400979]
 ======= Memory map: ========
 00400000-00401000 r-xp 00000000 08:01 3540826                            /home/test/biaoc/C/C++/day04/a.out
 00601000-00602000 r--p 00001000 08:01 3540826                            /home/test/biaoc/C/C++/day04/a.out
 00602000-00603000 rw-p 00002000 08:01 3540826                            /home/test/biaoc/C/C++/day04/a.out
 02247000-02279000 rw-p 00000000 00:00 0                                  [heap]
 7fa678000000-7fa678021000 rw-p 00000000 00:00 0 
 7fa678021000-7fa67c000000 ---p 00000000 00:00 0 
 7fa67fd80000-7fa67fe88000 r-xp 00000000 08:01 3671889                    /lib/x86_64-linux-gnu/libm-2.23.so
 7fa67fe88000-7fa680087000 ---p 00108000 08:01 3671889                    /lib/x86_64-linux-gnu/libm-2.23.so
 7fa680087000-7fa680088000 r--p 00107000 08:01 3671889                    /lib/x86_64-linux-gnu/libm-2.23.so
 7fa680088000-7fa680089000 rw-p 00108000 08:01 3671889                    /lib/x86_64-linux-gnu/libm-2.23.so
 7fa680089000-7fa680249000 r-xp 00000000 08:01 3675108                    /lib/x86_64-linux-gnu/libc-2.23.so
 7fa680249000-7fa680449000 ---p 001c0000 08:01 3675108                    /lib/x86_64-linux-gnu/libc-2.23.so
 7fa680449000-7fa68044d000 r--p 001c0000 08:01 3675108                    /lib/x86_64-linux-gnu/libc-2.23.so
 7fa68044d000-7fa68044f000 rw-p 001c4000 08:01 3675108                    /lib/x86_64-linux-gnu/libc-2.23.so
 7fa68044f000-7fa680453000 rw-p 00000000 00:00 0 
 7fa680453000-7fa680469000 r-xp 00000000 08:01 3675127                    /lib/x86_64-linux-gnu/libgcc_s.so.1
 7fa680469000-7fa680668000 ---p 00016000 08:01 3675127                    /lib/x86_64-linux-gnu/libgcc_s.so.1
 7fa680668000-7fa680669000 rw-p 00015000 08:01 3675127                    /lib/x86_64-linux-gnu/libgcc_s.so.1
 7fa680669000-7fa6807db000 r-xp 00000000 08:01 1058868                    /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.21
 7fa6807db000-7fa6809db000 ---p 00172000 08:01 1058868                    /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.21
 7fa6809db000-7fa6809e5000 r--p 00172000 08:01 1058868                    /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.21
 7fa6809e5000-7fa6809e7000 rw-p 0017c000 08:01 1058868                    /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.21
 7fa6809e7000-7fa6809eb000 rw-p 00000000 00:00 0 
 7fa6809eb000-7fa680a11000 r-xp 00000000 08:01 3671885                    /lib/x86_64-linux-gnu/ld-2.23.so
 7fa680bf3000-7fa680bf9000 rw-p 00000000 00:00 0 
 7fa680c0f000-7fa680c10000 rw-p 00000000 00:00 0 
 7fa680c10000-7fa680c11000 r--p 00025000 08:01 3671885                    /lib/x86_64-linux-gnu/ld-2.23.so
 7fa680c11000-7fa680c12000 rw-p 00026000 08:01 3671885                    /lib/x86_64-linux-gnu/ld-2.23.so
 7fa680c12000-7fa680c13000 rw-p 00000000 00:00 0 
 7fffb5bac000-7fffb5bcd000 rw-p 00000000 00:00 0                          [stack]
 7fffb5be0000-7fffb5be3000 r--p 00000000 00:00 0                          [vvar]
 7fffb5be3000-7fffb5be5000 r-xp 00000000 00:00 0                          [vdso]
 ffffffffff600000-ffffffffff601000 r-xp 00000000 00:00 0                  [vsyscall]
 已放弃 (核心已转储)
 */
