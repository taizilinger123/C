/*
 点菜练习
 */
#include <stdio.h>
int main(){
   int order = 0;
   printf("请输入编号: ");
   scanf("%d", &order);
#ifdef  ZHAOBENSHAN
   if(order == 1){
      printf("这个菜没有\n");
   }
   else{
      printf("这个真没有\n");
   }
#else 
   if(order == 1){
      printf("这个菜有\n");
   }
   else{
      printf("这个菜没有\n");
   }
#endif  //ZHAOBENSHAN
   return 0;
}


/*
 root@test:/home/test/biaoc/C/day14# gcc  -DZHAOBENSHAN  12order.c 
 root@test:/home/test/biaoc/C/day14# ./a.out 
 请输入编号: 1
 这个菜没有
 root@test:/home/test/biaoc/C/day14# ./a.out 
 请输入编号: 2
 这个真没有
 root@test:/home/test/biaoc/C/day14# gcc  12order.c 
 root@test:/home/test/biaoc/C/day14# ./a.out 
 请输入编号: 1
 这个菜有
 root@test:/home/test/biaoc/C/day14# ./a.out 
 请输入编号: 2
 这个菜没有
 */
