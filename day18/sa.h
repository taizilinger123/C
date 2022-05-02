#ifndef _SA_H/*防止重复include*/
#define _SA_H
#include <sys/types.h>
typedef struct Stack{/*定义堆栈结构*/
   int*  arr;/*指针代表数组*/
   size_t cap;/*数组容量/大小*/
   size_t top;/*栈顶指针*/
}STACK;
/*分配内存，并初始化栈*/
void stack_init(STACK* stack,size_t cap);
/*释放内存并恢复状态*/
void stack_deinit(STACK* stack);
/*判断栈是否满/空*/
int stack_full(STACK* stack);
int stack_empty(STACK* stack);
/*压入/弹出数据*/
void stack_push(STACK* stack,int data);
int stack_pop(STACK* stack);
/*查看栈顶,与弹出数据的区别在于top不变*/
int stack_top(STACK* stack);
size_t stack_size(STACK* stack);//取栈中元素数
#endif
