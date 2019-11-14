#include <stdio.h>
#include <stdlib.h>

int main()
{
   printf("before sys\n");
   
   //1、需要头文件 #include <stdlib.h>
   //2、system功能: 调用外部程序   
   system("./waibu");

   printf("after sys\n");

   return 0;
}
