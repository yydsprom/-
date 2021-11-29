#include<stdio.h>
#include<stdlib.h>
typedef struct treeNode
{
    char data;
    struct treeNode *Lchild;
    struct treeNode *Rchild;
}TREE,*LPTREE;

LPTREE createNode(char data)
{
    LPTREE newNode = (LPTREE)malloc(sizeof(TREE));
    newNode->data = data ;
    newNode->Lchild = NULL;
    newNode->Rchild = NULL;
    return newNode;

}

void  insertNode(LPTREE parentNode,LPTREE LChild ,LPTREE RChild)
{
    parentNode->Lchild = LChild;
    parentNode->Rchild = RChild;
}

void printfCurNodeData(LPTREE curData)
{
    printf("%c\t",curData->data);
}

//递归法先序：根，左，右
void  preOrder(LPTREE root)
{
    if(root != NULL)
    {
        printfCurNodeData(root);
        preOrder(root->Lchild);
        preOrder(root->Rchild);
    }

}

//中序：左，根，右
void midOrder(LPTREE root)
{
    if(root != NULL )
    {
        midOrder(root->Lchild);  //左
        printfCurNodeData(root);//根
        midOrder(root->Rchild);//右
    }
}

//后序：左，右,根
void lastOrder(LPTREE root)
{
    if(root != NULL)
    {
        lastOrder(root->Lchild);
        lastOrder(root->Rchild);
        printfCurNodeData(root);
    }
}

//先序遍历：非递归（根，左，右）
void preOderByStack(LPTREE root)
{
    if(root == NULL)
        return;
    //准备栈
    struct treeNode*  stack[10];   //存储每次打印结点的位置
    int stackTop = -1;  //栈顶标记
    LPTREE pMove = root; //从根节点开始做打印
    while(stackTop !=-1  || pMove )   //没有栈可以退
    {
        //根，左，右
        //找到最左边的结点
        while(pMove)
        {
            //把路径入栈+打印走过的结点
            printf("%c\t",pMove->data);
            stack[++stackTop] = pMove;
            pMove = pMove->Lchild;
        }
        //无路可走的处理
        if(stackTop != -1)
        {
            pMove =  stack[stackTop];   //获取栈顶元素
            stackTop--;                 //出栈
            pMove = pMove->Rchild;
        }

    }
}

//中序：左，根，右

int main()
{
   LPTREE A = createNode('A');
   LPTREE B = createNode('B');
   LPTREE C = createNode('C');
   LPTREE D = createNode('D');
   LPTREE E = createNode('E');
   LPTREE F = createNode('F');
   LPTREE G = createNode('G');
   insertNode(A,B,C);
   insertNode(B,D,NULL);
   insertNode(D,NULL,G);
   insertNode(C,E,F);
   printf("先序遍历：\n");
   preOrder(A);
   preOderByStack(A);
   printf("\n中序遍历：\n");
   midOrder(A);
   printf("\n后序遍历：\n");
   lastOrder(A);
   return 0;
}