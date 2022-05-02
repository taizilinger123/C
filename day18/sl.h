#ifndef _SL_H
#define _SL_H

#include <sys/types.h>
typedef struct StackNode{/*struct 节点*/
   int data;//数据
   struct StackNode*  next;//下一个节点的地址
} STACK_NODE;
typedef struct Stack{/*struct 堆栈*/
   STACK_NODE* top;//栈顶元素(链式表的首节点)
} STACK;

void stack_init(STACK* stack);//分配内存初始化
void stack_deinit(STACK* stack);//释放内存恢复
int stack_empty(STACK* stack);//判断空
void stack_push(STACK* stack,int data);//入栈
int stack_pop(STACK* stack);//出栈
int stack_top(STACK* stack);//查看栈顶
size_t stack_size(STACK* stack);//元素个数
#endif
