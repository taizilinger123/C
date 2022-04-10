#include <stdio.h>
#include "09agenda.h"
int main(){
   int num = 0, pos = 0; 
   printf("请输入日程个数: ");
   scanf("%d", &num);
   item items[num];
   for(pos = 0;pos <= num - 1;pos++){
      read(items + pos);
   }
   for(pos = 0;pos <= num - 1;pos++){
      write(items + pos);
   }
   return 0;
}
