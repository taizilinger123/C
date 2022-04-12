/*
 贪吃蛇练习
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct {
   int x, y;
} pt;
//把蛇的位置信息打印在屏幕上
void  print(const pt *p_snake, int size){
    int pos = 0;
	for(pos = 0;pos <= size - 1;pos++){
	   printf("(%d, %d) ", (p_snake + pos)->x, (p_snake + pos)->y);
	}
	printf("\n");
}
//生成蛇开始的位置数字
void create_snake(pt *p_snake, int size){
    p_snake->x = rand() % 100; //p_snake->x是取结构体的x的值
	p_snake->y = rand() % 100;
	int pos = 0;
	for(pos = 1;pos <= size - 1;pos++){
	    *(p_snake + pos) = *(p_snake + pos - 1);
		(p_snake + pos)->x++;
		/*
		 p_snake[pos] = p_snake[pos - 1];
		 p_snake[pos].x++;
		 */
	}
}
int main(){
  pt snake[3];
  srand(time(0));
  create_snake(snake, 3);
  print(snake, 3);
  return 0;
}
