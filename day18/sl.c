#include <stdlib.h>
#include "sl.h"
//额外提供两个函数-创建节点和销毁节点
static STACK_NODE* create_node(int data, STACK_NODE* next){
   STACK_NODE* node = malloc(sizeof(STACK_NODE));
   node->data = data;
   node->next = next;
   return node;
}
static STACK_NODE* destroy_node(STACK_NODE* node){
   STACK_NODE* next = node->next;//先取下一个
   free(node);
   return next;
}
void stack_init(STACK* stack){
   stack->top = NULL;
}//初始化第一个节点为NULL
void stack_deinit(STACK* stack){
   while(stack->top){//删到返回NULL为止
      stack->top = destroy_node(stack->top);
   }
}//释放内存恢复
int stack_empty(STACK* stack){
   return !stack->top;
}//判断空
void stack_push(STACK* stack,int data){
   stack->top = create_node(data,stack->top);
}//入栈
int stack_pop(STACK* stack){
   int data = stack->top->data;//先取值
   stack->top = destroy_node(stack->top);
   return data;
}//出栈
int stack_top(STACK* stack){
   return stack->top->data;
}//查看栈顶
size_t stack_size(STACK* stack){
   size_t size = 0;
   STACK_NODE* node = stack->top;
   while(node/*!= NULL*/){
     size++;
	 node = node->next;
   }
   return size;
}//元素个数
