#include <stdlib.h>
#include "ls.h"
//创建新的节点
static LIST_NODE* create_node(int data, LIST_NODE* prev,LIST_NODE* next){
     LIST_NODE* node=malloc(sizeof(LIST_NODE));
	 node->data = data;
	 node->prev = prev;
	 node->next = next;
     return node;
}
static LIST_NODE* destroy_node(LIST_NODE* node,LIST_NODE** prev){//prev取前节点
     LIST_NODE* next = node->next;
	 if(prev/*!=NULL*/) *prev = node->prev;
	 free(node);
     return next;
}//返回后节点，用指针获取前节点
void list_init(LIST* list){//初始化List
    list->head = NULL;
	list->tail = NULL;
}
void list_deinit(LIST* list){//释放并恢复
    while(list->head){
	   list->head = destroy_node(list->head,0);
	   list->tail = NULL;
	}
}
