#include <stdio.h>
#include <sys/mman.h>
#include <string.h>

int main(){
   void* p = mmap(0,//映射的首地址 0是让内核指定
     4,//映射的大小，不足一页补充一页
	 PROT_READ|PROT_WRITE,//内存权限(读写权限)
	 MAP_PRIVATE|MAP_ANONYMOUS,//前者是私有映射
	//和MAP_SHARED对应 必须2选1;后者特指物理内存 
	 0,//文件描述符
	 0);//文件的偏移量
   if(p == MAP_FAILED){//失败,值(void*)-1
     perror("mmap");
	 return -1;//return代表返回,不能连接语句
   }
   int* pi = p; *pi = 100;
   char* str =(char*)(pi+10);// 40字节以后
   strcpy(str,"ABCDEFG");
   pi = p+60;// 60字节以后
   int i;
   for(i=0;i<20;i++){ pi[i] = 97+i;}
   char* ch = p;
   for(i=0;i<160;i++){
     if(i%10 == 0) printf("\n");
	 printf("%d ",ch[i]);
   }
   munmap(p,4);//解除映射
}
