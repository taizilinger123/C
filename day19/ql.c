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
void queue_push(QUEUE* queue,int data){//压入
   QUEUE_NODE* rear = create_node(data);
   if(queue->rear)//尾节点非空，有队首
	 queue->rear->next = rear;//改原来队尾next
   else//空队列
	 queue->front = rear;//队首就是新元素
   queue->rear = rear;//设定新的尾节点
}
int queue_pop(QUEUE* queue){//弹出
   int data = queue->front->data;
   queue->front = destroy_node(queue->front);
   if(queue->front == NULL) queue->rear=NULL;
   return data;
}
int queue_front(QUEUE* queue){//查看队首
   return queue->front->data;
}
size_t queue_size(QUEUE* queue){//元素个数
   size_t size = 0;
   QUEUE_NODE* node = NULL;
   for(node=queue->front;node;node=node->next){
      size++;
   return size;
   }
}
//gcc  -c  ql.c
