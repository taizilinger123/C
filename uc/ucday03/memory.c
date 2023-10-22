#include <stdio.h>
#include <stdlib.h>

int  i1 = 10;//全局区
int  i2 = 20;//全局区
int  i3;//bss
static int i4 = 40;//全局
const int i5 = 50;//只读常量区
void fa(int i6){//栈
	int i7 = 70;//栈
	static int i8 = 80;//全局
	const int i9 = 90;//栈
	int* pi = malloc(4);//堆
	char* st1 ="abcdef";//只读常量
	char st2[] = "abcdef";//栈,在栈中复制了字符串的内容
    printf("i6=%p\n",&i6);
    printf("i7=%p\n",&i7);
    printf("i8=%p\n",&i8);
    printf("i9=%p\n",&i9);
    printf("pi=%p\n",pi);
    printf("st1=%p\n",st1);
    printf("st2=%p\n",st2);
}
int main(){
    printf("i1=%p\n",&i1);
    printf("i2=%p\n",&i2);
    printf("i3=%p\n",&i3);
    printf("i4=%p\n",&i4);
    printf("i5=%p\n",&i5);
    fa(100);
    printf("fa=%p\n",fa);//代码区
	printf("pid=%d\n",getpid());//取进程ID
	while(1);
}//gcc memory.c /a.out运行后，用cat /proc/进程ID/maps 查看内存

/*
 root@test:/home/test/biaoc/C/uc/ucday03# gcc  memory.c 
 memory.c: In function ‘main’:
 memory.c:32:20: warning: implicit declaration of function ‘getpid’ [-Wimplicit-function-declaration]
   printf("pid=%d\n",getpid());//取进程ID
                       ^
					   root@test:/home/test/biaoc/C/uc/ucday03# a.out
					   i1=0x601050
					   i2=0x601054
					   i3=0x601064
					   i4=0x601058
					   i5=0x400854
					   i6=0x7ffc4ebd7aac
					   i7=0x7ffc4ebd7ab8
					   i8=0x60105c
					   i9=0x7ffc4ebd7abc
					   pi=0x1593420
					   st1=0x400858
					   st2=0x7ffc4ebd7ad0
					   fa=0x400626
					   pid=62350    //pid号码
root@test:/home/test/biaoc/C/uc/ucday03# cat /proc/62350/maps 
00400000-00401000 r-xp 00000000 08:01 3148882                            
00600000-00601000 r--p 00000000 08:01 3148882                            
00601000-00602000 rw-p 00001000 08:01 3148882                            
01593000-015b4000 rw-p 00000000 00:00 0                                  
7efcef7a8000-7efcef968000 r-xp 00000000 08:01 3675108                    
7efcef968000-7efcefb68000 ---p 001c0000 08:01 3675108                    
7efcefb68000-7efcefb6c000 r--p 001c0000 08:01 3675108                    
7efcefb6c000-7efcefb6e000 rw-p 001c4000 08:01 3675108                    
7efcefb6e000-7efcefb72000 rw-p 00000000 00:00 0 
7efcefb72000-7efcefb98000 r-xp 00000000 08:01 3671885                    
7efcefd7c000-7efcefd7f000 rw-p 00000000 00:00 0 
7efcefd97000-7efcefd98000 r--p 00025000 08:01 3671885                    
7efcefd98000-7efcefd99000 rw-p 00026000 08:01 3671885                    
7efcefd99000-7efcefd9a000 rw-p 00000000 00:00 0 
7ffc4ebb8000-7ffc4ebd9000 rw-p 00000000 00:00 0                          
7ffc4ebe8000-7ffc4ebeb000 r--p 00000000 00:00 0                          
7ffc4ebeb000-7ffc4ebed000 r-xp 00000000 00:00 0                          
ffffffffff600000-ffffffffff601000 r-xp 00000000 00:00 0 
 */
