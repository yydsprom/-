#include<stdio.h>
#include<stdlib.h>
typedef struct treenode
{
    char data;
    struct treenode *lchild,*rchild;   //左孩子，右孩子指针
    int ltag,rtag;      //左右标志域
}*LPtree;


//找到第一个中序遍历的结点
LPtree Firstnode(LPtree root)
{
    while(root->ltag==0)  root = root->lchild;
    return root;
}

//在中序线索二叉树中找到后继
LPtree Nextnode(LPtree node)
{
    if(node->rtag==0)  return Firstnode(node->rchild);
    else return node->rchild;
}

void Inorder(LPtree root)  //中序遍历
{
    LPtree p = Firstnode(root);
    while(p!=NULL)
    {
        visit(p);
        p=Nextnode(p);
    }
}



#include<stdio.h>
#include<stdlib.h>

//找到以root为根的子树中，最后一个被中序遍历的结点
LPtree Lastnode(LPtree root)  
{
    while(root->rtag==0)
        root = root->rchild;
    return root;
}

//在中序线索二叉树中找到结点的前驱结点
LPtree Prenode(LPtree p)
{
    if(p->ltag==0) return(Lastnode(p->lchild));
    else return p->lchild;

}

//对中序线索二叉树进行逆向中序遍历
void RevInoreder(LPtree root)
{
    LPtree p = Lastnode(root);
    while(p!=NULL)
    {
        visit(p);
        p = Prenode(p);
    }

}


//在先序线索二叉树中找到后继
LPtree Nextnode(LPtree node)
{
    if(node->rtag==1)
        node = node->rchild;
    else
    {
        if(node->lchild!=NULL)
            node = node->lchild;
        else
            node = node->rchild;
    
    }
    return node;
}


//在先序线索二叉树中找到前驱
LPtree Prenode(LPtree p)
{
    if(p->ltag==0)
        p->lchild;
    else
    {
        //不行了（土办法从头遍历）
    }
}


//在后序线索二叉树中找到前驱
LPtree Prenode(LPtree p)
{
    if(p->ltag==1)
        p = p->lchild;
    else
    {
        if(p->rchild!=NULL)
            p = p->rchild;
        else
            p = p->lchild;
    }
    return p;   
}





