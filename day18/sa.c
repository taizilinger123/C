#include <stdio.h>
#include <stdlib.h>
#include "sa.h"

void stack_init(STACK* stack,size_t cap){
  //(*stack).arr = 
  stack->arr = malloc(sizeof(int)*cap);
  stack->cap = cap;
  stack->top = 0;
}//分配内存并初始化
void stack_deinit(STACK* stack){
  free(stack->arr);
  stack->arr = NULL;
  stack->cap = 0;
  stack->top = 0;
}//释放内存并还原状态
int stack_full(STACK* stack){
   return stack->top >= stack->cap;
}//判断是否满
int stack_empty(STACK* stack){
   return !stack->top; //== 0;
}//判断是否空
void stack_push(STACK* stack,int data){
  stack->arr[stack->top/*++*/] = data;
  stack->top++;
}//入栈
int stack_pop(STACK* stack){
   stack->top--;
   return stack->arr[stack->top];
}//出栈
int stack_top(STACK* stack){
   return stack->arr[stack->top-1];
}//查看栈顶
size_t stack_size(STACK* stack){
   return stack->top;
}//取元素个数
//gcc -c sa.c
