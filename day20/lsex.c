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
void reverse(LIST_NODE* head){//逆转节点
    if(head && head->next){//2个节点需要逆转
	    reverse(head->next);//下一个节点逆转好
		head->next->next = head;//后节点的next
		head->next = NULL;//当前节点变尾节点
	}
}
void list_reverse(LIST* list){//逆转list
   reverse(list->head);//逆转节点
   LIST_NODE* temp = list->head;//交换首尾
   list->head = list->tail;
   list->tail = temp;
}
int list_middle(LIST* list){//取中间值
   LIST_NODE* mid = NULL,*node = NULL;
   for(mid=node=list->head;
	   node->next && node->next->next;
	   node=node->next->next){
       mid = mid->next;
   }
   return mid->data;
}
int main(){
   LIST list;
   list_init(&list);
   int i;
   for(i=1;i<6;i++) list_append(&list,i);
   list_rprint(&list);
   list_reverse(&list);
   list_print(&list);
   list_deinit(&list);
}

/*
 root@test:/home/test/biaoc/C/day20# gcc lsex.c
 root@test:/home/test/biaoc/C/day20# ./a.out 
 5 4 3 2 1 
 */
