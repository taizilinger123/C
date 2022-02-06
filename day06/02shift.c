/*
 移位操作练习
 */
#include <stdio.h>
int main(){
   printf("18 << 2是0x%x\n", 18 << 2);
   printf("18 >> 1是0x%x\n", 18 >> 1);
   printf("-1 << 2是0x%x\n", -1 << 2);
   printf("-1 >> 2是0x%x\n", -1 >> 2);
   printf("0xffffffff >> 2是0x%x\n", 0xffffffff >> 2);
   return 0;
}
