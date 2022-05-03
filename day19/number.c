#include <stdio.h>
#include "sl.h"

int main(){
   printf("请输入一个整数和一个进制\n");
   int num,base;
   scanf("%d",&num);//指针/字符串类型不取地址
   scanf("%d",&base);//基本类型/结构要取地址
   STACK stack;
   stack_init(&stack);
   do{
      stack_push(&stack,num%base);
   }while(num=num/base);//1除2赋值3判断num
   printf("转换结果: ");
   while(!stack_empty(&stack)){
       int temp = stack_pop(&stack);
	   if(temp<10) printf("%d",temp);
	   else printf("%c",temp-10+'A');
   }
   printf("\n");
   stack_deinit(&stack);
}

/*
 root@test:/home/test/biaoc/C/day19# gcc  number.c  sl.c
 root@test:/home/test/biaoc/C/day19# ./a.out 
 请输入一个整数和一个进制
 127
 2
 转换结果: 1111111
 root@test:/home/test/biaoc/C/day19# ./a.out 
 请输入一个整数和一个进制
 127
 8            1111111=1 111 111   8进制是2进制的变体，8进制用3个二进制表示
 转换结果: 177
 root@test:/home/test/biaoc/C/day19# ./a.out 
 请输入一个整数和一个进制
 127
 16           1111111=111 1111  16进制是2进制的变体，16进制用4个二进制表示
 转换结果: 7F

 */
