#include "qs.h"
void queue_init(QUEUE* queue){
   stack_init(&queue->is);
   stack_init(&queue->os);
}
void queue_deinit(QUEUE* queue){
   stack_deinit(&queue->is);
   stack_deinit(&queue->os);
}
int  queue_empty(QUEUE* queue){
   return stack_empty(&queue->is) && stack_empty(&queue->os);
}
void queue_push(QUEUE* queue,int data){
   stack_push(&queue->is,data); 
}
int  queue_pop(QUEUE* queue){//os空时从is导入
   if(stack_empty(&queue->os)){//从is向os导入
       while(!stack_empty(&queue->is))
		stack_push(&queue->os,stack_pop(&queue->is));
   }
   return stack_pop(&queue->os);
}
int  queue_front(QUEUE* queue){
   if(stack_empty(&queue->os)){//从is向os导入
       while(!stack_empty(&queue->is))
		 stack_push(&queue->os,stack_pop(&queue->is));
	  }
   return stack_top(&queue->os);
}
size_t queue_size(QUEUE* queue){
   return stack_size(&queue->is)+stack_size(&queue->os);
}
