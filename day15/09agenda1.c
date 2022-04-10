/*
 日程练习
 */
#include <stdio.h>
#include <string.h>
typedef struct {
   int time;
   char buf[20];
} item;
item *read(item *p_item){
   printf("请输入时间: ");
   scanf("%d", &(p_item->time));
   scanf("%*[^\n]");
   scanf("%*c");
   printf("请输入日程内容: ");
   fgets(p_item->buf, 20, stdin);
   if(strlen(p_item->buf)==19 && p_item->buf[18] != '\n' ){
         scanf("%*[^\n]");
		 scanf("%*c");
   }
   return p_item;
}
void write(const item *p_item){
   printf("时间是%d\n", p_item->time);
   printf("内容是%s\n", p_item->buf);
}
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
