#ifndef __LS_H
#define __LS_H
#include <sys/types.h>
typedef struct ListNode{//链表节点
   int data;//数据
   struct ListNode* prev;//前节点
   struct ListNode* next;//后节点 
} LIST_NODE;
typedef struct List{//链表
   LIST_NODE* head;//链表头指针
   LIST_NODE* tail;//链表尾指针
   LIST_NODE* frwd;//正向迭代指针，用于查询
   LIST_NODE* bkwd;//反向迭代指针，用于查询
} LIST;
/*初始化/释放链表的函数，.c文件提供节点函数*/
void list_init(LIST* list);
void list_deinit(LIST* list);
int  list_empty(LIST* list);
void list_append(LIST* list,int data);//追加
int  list_insert(LIST* list,size_t pos,int data);//在位置pos之前插入
int* list_at(LIST* list,size_t pos);//随机访问
int  list_erase(LIST* list,size_t pos);//删除
void list_remove(LIST* list,int data);//删除
void list_clear(LIST* list);//全部删除
size_t list_size(LIST* list);//元素个数
/*正向迭代函数*/
void list_begin(LIST* list);//开始
int* list_next(LIST* list);//取下一个
int* list_prev(LIST* list);//取上一个
int* list_current(LIST* list);//取当前数据
int list_end(LIST* list);//判断迭代结束
#endif
