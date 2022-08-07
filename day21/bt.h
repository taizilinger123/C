/*有序二叉树*/
#ifndef _BT_H
#define _BT_H
#include <sys/types.h>
typedef struct BsTreeNode{//树的节点，二叉链表
   int data;
   struct BsTreeNode* left;
   struct BsTreeNode* right;
} BSTREE_NODE;
typedef struct BsTree{
  BSTREE_NODE* root;//根节点(必须有)
  size_t size;//元素个数(不是必须)
} BSTREE;
void bstree_init(BSTREE* bstree);//初始化空树
void bstree_deinit(BSTREE* bstree);//释放恢复
//数据插入和删除
void bstree_insert(BSTREE* bstree,int data);
int bstree_erase(BSTREE* bstree,int data);
void bstree_clear(BSTREE* bstree);//清空
void bstree_update(BSTREE* bstree,int old,int new);//修改
//判断是否存在
int bstree_exist(BSTREE* bstree,int data);
void bstree_travel(BSTREE* bstree);//中序遍历
size_t bstree_size(BSTREE* bstree);//元素个数
size_t bstree_height(BSTREE* bstree);//高度
#endif
