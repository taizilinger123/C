/*
 字符练习
 */
#include <stdio.h>
int main(){
   printf("abc\rxy\n"); //\r回车字符意思就是xy换到ab位置所以输出xyc
   printf("abc\txy\n"); // \t下一段的开头，就是竖的方向上是与下一行对齐的
   printf("abcde\txy\n"); 
   printf("\\  \' \"\n");
   return 0;
}
