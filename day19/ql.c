#include <stdlib.h>
#include "ql.h"

static QUEUE_NODE*  create_node(int data){
   QUEUE_NODE* node=malloc(sizeof(QUEUE_NODE));
   node->data = data;
   node->next = NULL;
   return node;
}//创建节点
static QUEUE_NODE*  destroy_node(QUEUE_NODE* node){
   QUEUE_NODE* next = node->next;
   free(node);
   return next;
}//销毁节点
void queue_init(QUEUE* queue){//初始化空队列
   queue->front = NULL;
   queue->rear = NULL;
}
void queue_deinit(QUEUE* queue){//释放内存
   while(queue->front)
	   queue->front = destroy_node(queue->front);
   queue->rear = NULL;
}
int queue_empty(QUEUE* queue){//判断空
   return (!queue->front) && (!queue->rear);
}
void queue_push(QUEUE* queue,int data){
    
}
