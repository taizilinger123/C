#ifndef _QA_H
#define _QA_H
#include <sys/types.h>
typedef struct Queue{ //结构体 队列
  int* arr;//数组指针
  size_t cap;//数组容量(长度)
  size_t front;//对首下标(弹出)
  size_t rear;//队尾下标(压入)
  size_t size;//元素数量(判断空满)
} QUEUE;
/*入队arr[rear]=data;rear++;(判断不满)*/
/*出队front++;return arr[front-1];(判断不空)*/
/*分配内存并初始化*/
void queue_init(QUEUE* queue,size_t cap);
/*释放内存并恢复状态*/
void queue_deinit(QUEUE* queue);
/*判断队列满或空*/
int queue_full(QUEUE* queue);
int queue_empty(QUEUE* queue);
/*入队和出队*/
void queue_push(QUEUE* queue,int data);
int queue_pop(QUEUE* queue);
/*查看对首和取元素数量*/
int queue_front(QUEUE* queue);
size_t queue_size(QUEUE* queue);
#endif
