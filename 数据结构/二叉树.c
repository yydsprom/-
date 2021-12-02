#include<stdio.h>
#include<stdlib.h>
int count = 0;
int count1 = 0;
int depth = 0;
typedef struct treeNode
{
    char data;
    struct treeNode* Lchild;
    struct treeNode* Rchild;
}TREE, * LPTREE;
 
LPTREE createNode(char data)
{
    LPTREE newNode = (LPTREE)malloc(sizeof(TREE));
    newNode->data = data;
    newNode->Lchild = NULL;
    newNode->Rchild = NULL;
    return newNode;
 
}
 
void  insertNode(LPTREE parentNode, LPTREE LChild, LPTREE RChild)
{
    parentNode->Lchild = LChild;
    parentNode->Rchild = RChild;
}
 
void printfCurNodeData(LPTREE curData)
{
    printf("%c\t", curData->data);
}
 
//递归法先序：根，左，右
void  preOrder(LPTREE root)
{
    if (root != NULL)
    {
        printfCurNodeData(root);
        preOrder(root->Lchild);
        preOrder(root->Rchild);
    }
 
}
 
//中序：左，根，右
void midOrder(LPTREE root)
{
    if (root != NULL)
    {
        midOrder(root->Lchild);  //左
        printfCurNodeData(root);//根
        midOrder(root->Rchild);//右
    }
}
 
//后序：左，右,根
void lastOrder(LPTREE root)
{
    if (root != NULL)
    {
        lastOrder(root->Lchild);
        lastOrder(root->Rchild);
        printfCurNodeData(root);
    }
}
 
//先序遍历：非递归（根，左，右）
void preOderByStack(LPTREE root)
{
    if (root == NULL)
        return;
    //准备栈
    struct treeNode* stack[10];   //存储每次打印结点的位置
    int stackTop = -1;  //栈顶标记
    LPTREE pMove = root; //从根节点开始做打印
    while (stackTop != -1 || pMove)   //没有栈可以退
    {
        //根，左，右
        //找到最左边的结点
        while (pMove)
        {
            //把路径入栈+打印走过的结点
            printf("%c\t", pMove->data);
            stack[++stackTop] = pMove;
            pMove = pMove->Lchild;
        }
        //无路可走的处理
        if (stackTop != -1)
        {
            pMove = stack[stackTop];   //获取栈顶元素
            stackTop--;                 //出栈
            pMove = pMove->Rchild;
        }
 
    }
}
 
 //中序：左，根，右
void midOrderBystack(LPTREE root)
{
    if (root == NULL)
        return;
    //栈的准备动作
    struct treeNode* stack[10];
    int stackTop = -1;
    //定义移动的指针
    LPTREE pMove = root;
    while (stackTop != -1 || pMove)
    {
        //走到最左边，把走过的结点入栈
        while (pMove)
        {
            stack[++stackTop] = pMove;
            pMove = pMove->Lchild;
        }
        //出栈
        if (stackTop != -1)
        {
            pMove = stack[stackTop--];
            printf("%c\t", pMove->data);
            pMove = pMove->Rchild;
        }
 
    }
 
}
 
 
//后序遍历  左，右，根
 
void lastOrderByStack(LPTREE root)
{
    LPTREE pMove;
    LPTREE printed;
    pMove = root;
    printed = NULL;
    LPTREE stack[10];
    int stackTop = -1;
    while (pMove != NULL || stackTop != -1)
    {
        while (pMove!=NULL)
        {
            stack[++stackTop] = pMove;
            pMove = pMove->Lchild;
        }
        if (stackTop != -1)
        {
            pMove = stack[stackTop];
            if (pMove->Rchild == NULL || pMove->Rchild == printed)
            {
                stackTop--;
                printf("%c\t", pMove->data);
                printed = pMove;
                pMove = NULL;
            }
            else
            {
                pMove = pMove->Rchild;
            }
        }
 
    }
 
}
 
 
//层序遍历
 
void levelOrder(LPTREE root)
{
    if (root == NULL)
        return;
    //创建一个队列
    LPTREE p;
    struct treeNode *queue[10];
    int front, rear;
    front = rear = 9; 
    rear = (rear + 1) % 10;
    queue[rear] = root;
    while (rear != front)  //如果队列不为空
    {
        front = (front + 1) % 10;
        p = queue[front];
        printf("%c\t", p->data);
        if (p->Lchild != NULL)
        {
            rear = (rear + 1) % 10;
            queue[rear] = p->Lchild;
 
        }
        if (p->Rchild != NULL)
        {
            rear = (rear + 1) % 10;
            queue[rear] = p->Rchild;
        }
 
    }
    
}
 
void numByPreOrder(LPTREE root)   //统计二叉树结点
{
    if (root)
    {
        count++;
        numByPreOrder(root->Lchild);
        numByPreOrder(root->Rchild);
    }
}
 
void PrintleafNode(LPTREE root)   //打印叶子结点
{
    if (root != NULL)
    {
 
        PrintleafNode(root->Lchild);
        PrintleafNode(root->Rchild);
        if (root->Lchild == NULL && root->Rchild == NULL)
        {
            printf("%c\t", root->data);
          
        }
    }
}
 
 
void numleafNode(LPTREE root)   //求叶子结点的和 方法1
{
    if (root != NULL)
    {
        numleafNode(root->Lchild);
        numleafNode(root->Rchild);
        if (root->Lchild == NULL && root->Rchild == NULL)
          count1++;
    }
}
 
 
int leaf(LPTREE root)//求叶子结点的和 方法2
{
    int ln, rn;
    if (root == NULL)
        return 0;
    if ((root->Lchild == NULL) && (root->Rchild == NULL))
        return 1;
    ln = leaf(root->Lchild);
    rn = leaf(root->Rchild);
    return(ln + rn); 
 
}
 
 
void TreeDepth(LPTREE root,int h)   //求二叉树的高度方法1
{
    if (root != NULL)
    {
        if (h > depth) depth = h;
        TreeDepth(root->Lchild,h+1);
        TreeDepth(root->Rchild,h+1);
    }
 
}
 
int TreeDepth2(LPTREE root)   //求二叉树的高度方法2
{
    int hl = 0, hr = 0, h = 0;
 
    if (root == NULL)
        return 0;
    else
    {
        hl = TreeDepth2(root->Lchild);
        hr = TreeDepth2(root->Rchild);
        h = (hl > hr ? hl : hr) + 1;
        return h;
    }
 
}
 
LPTREE parent(LPTREE root, LPTREE current) //求二叉树的current结点的双亲
{
    LPTREE p;
    if (root == NULL)
        return NULL;
    if (root->Lchild == current || root->Rchild == current)
        return root;       //root就为current的双亲
    p = parent(root->Lchild, current);
    if (p != NULL)
        return p;
    else return(parent(root->Rchild , current));
}
 
int like(LPTREE t1, LPTREE t2)    //判断两棵树是否相等
{
    int like1, like2;
    if (t1 == NULL && t2 == NULL)
        return 1;
    if (t1 == NULL || t2 == NULL)
        return 0;
    like1 = like(t1->Lchild, t2->Lchild);
    like2 = like(t2->Rchild, t2->Rchild);
    return(like1 && like2);
}
 
void Printtree(LPTREE root,int h)  //  按照右根左的方式进行打印
{
    if (root == NULL)
        return;
    Printtree(root->Rchild,h+1);   //先打印右子树
    for (int i = 0; i < h; i++)
        printf("  ");              //层次决定结点的左右位置
    printf("%c\n", root->data);         
    Printtree(root->Lchild, h + 1);     //后打印左子树
}
 
 
int main()
{
    LPTREE A = createNode('A');
    LPTREE B = createNode('B');
    LPTREE C = createNode('C');
    LPTREE D = createNode('D');
    LPTREE E = createNode('E');
    LPTREE F = createNode('F');
    LPTREE G = createNode('G');
    insertNode(A, B, C);
    insertNode(B, D, NULL);
    insertNode(D, NULL, G);
    insertNode(C, E, F);
    printf("先序遍历：\n");
    preOrder(A);
    preOderByStack(A);
    printf("\n中序遍历：\n");
    midOrder(A);
    midOrderBystack(A);
    printf("\n后序遍历：\n");
    lastOrder(A);
    lastOrderByStack(A);
    printf("\n层序遍历：\n");
    levelOrder(A);
    printf("\n统计总结点数\n");
    numByPreOrder(A);
    printf("%d", count);
    printf("\n打印叶子结点\n");
    PrintleafNode(A);
    printf("\n打印叶子结点总数\n");
    numleafNode(A);
    printf("%d", count1);
    printf("\n打印叶子结点总数\n");
    printf("%d", leaf(A));
    printf("\n求二叉树的高度\n");
    TreeDepth(A, 1);
    printf("%d", depth);
    printf("\n%d\n", TreeDepth2(A));
    printf("\n按照树的形式打印二叉树\n");
    Printtree(A,1);
    return 0;
}