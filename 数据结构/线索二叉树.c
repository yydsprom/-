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

void CreateInThread(LPtree root)
{
    if(root)
    {
        InThread(root);
        if(pre->rchild==NULL)
            pre->rtag = 1;
    }



}

int main()
{
    




}