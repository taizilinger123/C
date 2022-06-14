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
int list_empty(LIST* list){//判断空
    return !list->head && !list->tail;
}
void list_append(LIST* list,int data){//追加
    list->tail=create_node(data,list->tail,0);
	if(list->tail->prev)//不是首节点
		list->tail->prev->next = list->tail;
	else list->head = list->tail;//首节点
}
int list_insert(LIST* list,size_t pos,int data){//前插，返回1代表成功，0失败
    LIST_NODE* find = NULL;
    for(find=list->head;find;find=find->next){
	   if(! pos--){//到了插入的位置
	     LIST_NODE* node=create_node(data,find->prev,find);
		 if(node->prev)
			 node->prev->next = node;
		 else list->head = node;
		 node->next->prev = node;//后节点的前节点
		 return 1;
	   }
	}
	return 0;
}
int* list_at(LIST* list,size_t pos){//随机访问
    LIST_NODE* find = NULL;
	for(find=list->head;find;find=find->next){
	   if(! pos--) return &find->data;
	}
	return NULL;
}
int list_erase(LIST* list,size_t pos){
    LIST_NODE* find = NULL;
	for(find=list->head;find;find=find->next){
	   if(! pos--){
	        LIST_NODE* prev = NULL;
			LIST_NODE* next = destroy_node(find,&prev);
			if(prev) prev->next = next;//非  首节点
			else list->head = next;//首节点
			if(next) next->prev = prev;//非  尾节点
			else list->tail = prev;//尾节点
			return 1;
	   }
	}
	return 0;
}//按位置删除
void list_remove(LIST* list,int data){
   LIST_NODE* find=NULL;
   for(find=list->head;find;find=find->next){
	  if(find->data == data){//被删除的节点
	      LIST_NODE* prev = NULL;
		  LIST_NODE* next = destroy(find,&prev);
          if(prev) prev->next = next;
		  else list->head = next;
		  if(next) next->prev = prev;
		  else list->tail = prev;
	  }
   }
}//按数据删除

}
