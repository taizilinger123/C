#ifndef _QL_H
#define _QL_H
#include <sys/types.h>
typedef struct QueueNode{
   int data;//数据
   struct QueueNode* next;//下一个节点地址
} QUEUE_NODE;
typedef struct Queue{
   QUEUE_NODE* front;//队首
   QUEUE_NODE* rear;//队尾
} QUEUE;
void queue_init(QUEUE* queue);//初始化队列
void queue_deinit(QUEUE* queue);//释放并恢复
int queue_empty(QUEUE* queue);//判断空
void queue_push(QUEUE* queue,int data);//入队
int queue_pop(QUEUE* queue);//出队
int queue_front(QUEUE* queue);//查看队首
size_t queue_size(QUEUE* queue);//元素个数
#endif
