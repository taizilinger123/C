#include <stdio.h>
#include <stdlib.h>
#include "bt.h"

static BSTREE_NODE* create_node(int data){
  BSTREE_NODE* node = malloc(sizeof(BSTREE_NODE));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}
static void destroy_node(BSTREE_NODE* node){
  free(node);//删除节点
}
void bstree_init(BSTREE* bstree){//初始化
   bstree->root = NULL;
   bstree->size = 0;
}
/*各种递归函数的区域*/
static void clear(BSTREE_NODE** root){//清空
   if(*root){//判断非空
      clear(&(*root)->left);//清 左子树
	  clear(&(*root)->right);//清 右子树
	  destroy_node(*root);//回收 节点资源
	  *root = NULL;//把野指针变成空指针
   }//遇到NULL退出   
}
static void insert(BSTREE_NODE* node, BSTREE_NODE** root){
   if(! *root) *root = node;
   else if(node){
      if(node->data < (*root)->data)//小于
		  insert(node,&(*root)->left);//插入左子树
	  else
		  insert(node,&(*root)->right);
   }
}
/*************************/
void bstree_deinit(BSTREE* bstree){//释放恢复
   clear(&bstree->root);//用二级指针
   bstree->size = 0;
}
void bstree_insert(BSTREE* bstree,int data){
    insert(create_node(data),&bstree->root);
	bstree->size++;
}
