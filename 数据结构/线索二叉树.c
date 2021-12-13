#include<stdio.h>
#include<stdlib.h>
struct treenode *pre = NULL;  //设置全局变量pre

typedef struct treenode
{
    char data;
    struct treenode *lchild,*rchild;   //左孩子，右孩子指针
    int ltag,rtag;      //左右标志域
}*LPtree;

void visit(LPtree T)
{
    if(T->lchild == NULL)  //左树为空建立驱线索
    {
        T->lchild = pre;   //pre为全局变量
        T->ltag = 1;
    }
    if(pre!=NULL&&pre->rchild == NULL)
    {
        pre->rchild = T;   //建立前驱结点的后继结点
        pre->rtag = 1;   
    }
    pre = T;
}


void InThread(LPtree T)   //中序遍历一颗二叉树，一边遍历，一边进行线索化
{
    if(T != NULL)
    {
        InThread(T->lchild);
        visit(T);
        InThread(T->rchild);
    }
}

#include<stdio.h>
#include<stdlib.h>
struct Node * pre = NULL;
typedef struct Node
{
    int ltag,rtag;
    struct Node * lchild,* rchild;
    char data;
}*LPtree;

void visit(LPtree root)
{   
    if(root->lchild==NULL)
    {
        root->lchild = pre;
        root->ltag = 1;
    }
    if(pre->rchild==NULL&&pre!=NULL)
    {
        pre->rchild = root;
        pre->rtag = 1;
    }
    pre = root;
}

void PreThread(LPtree root)
{
    if(root!=NULL)
    {
        visit(root);
        if(root->ltag==0)
            PreThread(root->lchild);
        PreThread(root->rchild);
    }
}
void CreateInThread(LPtree root)
{
    if(root)
    {
        PreThread(root);
        if(pre->rchild==NULL)
            pre->rtag = 1;  //处理最后一个结点
    }
}


#include<stdio.h>
#include<stdlib.h>
struct Node * pre = NULL;
typedef struct Node
{
    int ltag,rtag;
    struct Node * lchild,* rchild;
    char data;
}*LPtree;

void visit(LPtree root)
{   
    if(root->lchild==NULL)
    {
        root->lchild = pre;
        root->ltag = 1;
    }
    if(pre->rchild==NULL&&pre!=NULL)
    {
        pre->rchild = root;
        pre->rtag = 1;
    }
    pre = root;
}

void PostThread(LPtree root)
{
    if(root!=NULL)
    {
        PostThread(root->lchild);
        PostThread(root->rchild);
        visit(root);
    }
}
void CreatePostThread(LPtree root)
{
    if(root)
    {
        PostThread(root);
        if(pre->rchild==NULL)
            pre->rtag = 1;  //处理最后一个结点
    }
}
