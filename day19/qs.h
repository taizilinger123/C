#ifndef  __QS_H
#define  __QS_H
#include "sl.h"
typedef struct Queue{
   STACK is;//第一次的栈，用来入栈
   STACK os;//第二次的栈，is出栈的入os,队列出
}QUEUE;
void queue_init(QUEUE* queue);
void queue_deinit(QUEUE* queue);
int  queue_empty(QUEUE* queue);
void queue_push(QUEUE* queue,int data);
int  queue_pop(QUEUE* queue);
int  queue_front(QUEUE* queue);
size_t queue_size(QUEUE* queue);
#endif 
