#include <stdlib.h>
#include "qa.h"

void queue_init(QUEUE* queue,size_t cap){
   queue->arr = malloc(cap*sizeof(int));
   queue->cap = cap;
   queue->front = 0;
   queue->rear = 0;
   queue->size = 0;
}
void queue_deinit(QUEUE* queue){
   free(queue->arr);
   queue->arr = NULL;
   queue->cap = 0;
   queue->front = 0;
   queue->rear = 0;
   queue->size = 0;
}
int queue_full(QUEUE* queue){
   return queue->size >= queue->cap;
}
int queue_empty(QUEUE* queue){
   return !queue->size; //==0;
}
void queue_push(QUEUE* queue,int data){//压入
   if(queue->rear >= queue->cap)
	   queue->rear = 0;
   queue->arr[queue->rear++] = data;
   ++queue->size;
}
int queue_pop(QUEUE* queue){
   if(queue->front >= queue->cap)
	   queue->front = 0;
   --queue->size;
   return queue->arr[queue->front++];
}
int queue_front(QUEUE* queue){
   if(queue->front >= queue->cap)
	   queue->front = 0;
   return queue->arr[queue->front];
}
size_t queue_size(QUEUE* queue){
   return queue->size; 
}
//gcc  -c  qa.c
