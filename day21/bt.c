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
static BSTREE_NODE** find(int data, BSTREE_NODE** root){
    if(! *root) 
		return root;
	else if(data == (*root)->data) 
		return root;
	else if(data < (*root)->data)
		return find(data,&(*root)->left);
	else 
		return find(data,&(*root)->right);
}//返回是数据父节点 left/right的地址 
static void travel(BSTREE_NODE* root){
   if(root){
      travel(root->left);//左子树
	  printf("%d ",root->data);//打印自己
	  travel(root->right);//右子树
   }
}
/*************************/
void bstree_travel(BSTREE* bstree){//中序遍历
   travel(bstree->root);
   printf("\n");
}
int bstree_erase(BSTREE* bstree,int data){
   //1 找到，用递归函数
   BSTREE_NODE** node = find(data,&bstree->root);
   if(*node){
	   //左子树插入右子树
       insert((*node)->left,&(*node)->right);
	   //切换位置
	   BSTREE_NODE* temp = *node;
	   *node = (*node)->right;
	   destroy_node(temp);//删除
	   --bstree->size;
	   return 1;
   }
   return 0;
}
void bstree_clear(BSTREE* bstree){
   bstree_deinit(bstree);
}
void bstree_update(BSTREE* bstree,int old,int new){
   while(bstree_erase(bstree,old)){
      bstree_insert(bstree,new);
   }//保证结果依然是 有序二叉树
}
int bstree_exist(BSTREE* bstree,int data){
   return *find(data,&bstree->root) != NULL;
}
size_t bstree_size(BSTREE* bstree){
   return bstree->size;
}
void bstree_deinit(BSTREE* bstree){//释放恢复
   clear(&bstree->root);//用二级指针
   bstree->size = 0;
}
void bstree_insert(BSTREE* bstree,int data){
    insert(create_node(data),&bstree->root);
	bstree->size++;
}

