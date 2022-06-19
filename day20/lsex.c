#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{//struct ListNode类型
   int data;
   struct ListNode* next;
} LIST_NODE; //LIST_NODE 是类型别名
typedef struct List{
   LIST_NODE*  head;
   LIST_NODE*  tail;
} LIST;
static LIST_NODE* create_node(int data){
   LIST_NODE* node = malloc(sizeof(LIST_NODE));
   node->data = data;
   node->next = NULL;
   return node;
}
static LIST_NODE* destroy_node(LIST_NODE* node){
   LIST_NODE* next = node->next;
   free(node);
   return next;
}
void list_init(LIST* list){
   list->head = NULL;
   list->tail = NULL;
}
void list_deinit(LIST* list){
   while(list->head){
     list->head = destroy_node(list->head);
   }
   list->tail = NULL;
}
void list_append(LIST* list,int data){
    LIST_NODE* node = create_node(data);
	if(list->tail) //不是首节点
		list->tail->next = node;
	else list->head = node;
	list->tail = node;//设置尾节点
}
size_t list_size(LIST* list){
    size_t size = 0;
	LIST_NODE* node = NULL;
	for(node=list->head;node;node=node->next)
		size++;
	return size;
}   
void list_print(LIST* list){
    LIST_NODE* node = NULL;
	for(node=list->head;node;node=node->next)
		printf("%d ",node->data);
	printf("\n");
}
void rprint(LIST_NODE* head){
    if(head){//head==NULL退出
	   rprint(head->next);//反向打印下一个节点
	   printf("%d ",head->data);
	}
}
void list_rprint(LIST* list){//反向打印函数
    rprint(list->head);//递归函数
	printf("\n");
}
