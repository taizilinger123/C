/*
 贪吃蛇练习,用到了结构体，枚举，函数，数组，指针
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
typedef struct {
   int x, y;
} pt;
enum {UP, DOWN, LEFT, RIGHT};
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
	int pos = 0;
    p_snake->x = rand() % 100; //p_snake->x是取结构体的x的值
	p_snake->y = rand() % 100;
	for(pos = 1;pos <= size - 1;pos++){
	    *(p_snake + pos) = *(p_snake + pos - 1);
		(p_snake + pos)->x++;
		/*
		 p_snake[pos] = p_snake[pos - 1];
		 p_snake[pos].x++;
		 */
	}
}
bool move_snake(pt *p_snake, int size){
	int direction = 0, pos = 0;
	pt head = *p_snake;
    printf("请选择方向(%d表示上，%d表示下，%d表示左，%d表示右): ", UP, DOWN, LEFT, RIGHT);    
	scanf("%d", &direction);
	//根据移动方向计算新蛇头位置
	if (direction == UP){
      head.y--;
	}
	else if (direction == DOWN){
	  head.y++;
	}
	else if (direction == LEFT){
	  head.x--;
	}
	else {
	  head.x++;
	}
	//检查新蛇头是否和原有格子重叠
	for (pos = 1;pos <= size - 1;pos++){
	  if((p_snake + pos)->x == head.x && 
		 (p_snake + pos)->y == head.y){
	       return false;
	  }
	}
	//把蛇身上的每个格子位置向后移动一位
	for(pos = size - 2;pos >= 0;pos--){
	    *(p_snake + pos + 1) = *(p_snake + pos);
	}
	//放置新蛇头
	*p_snake = head;
	return true;
}
int main(){
  pt snake[3];
  srand(time(0));
  create_snake(snake, 3);
  print(snake, 3);
  while(1){
    if (move_snake(snake, 3)){
	    print(snake, 3);
	}
	else {
	    printf("方向错误\n");
	}
  }
  return 0;
}
