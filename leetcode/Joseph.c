#include<stdio.h>
#include<stdlib.h>

typedef struct Node   
{
    int id;
    int password;
    struct Node*next;
}Node;

Node* create_node(int x,int y)  //创建结点
{
    Node*p = NULL;
    p = (Node*)malloc(sizeof(Node));
    p->id =x;
    p->password = y;
    p->next = NULL;
    return p;
}

Node * Create_List(int n)    //创建无头链表录入信息
{
    Node*head = NULL;//创建头指针
    Node *tail,*pnew;//创建一个新结点指针P和尾指针tail
    int id,password;
    for(int i=1;i<=n;i++)
    {
        printf("请输入第%d个人的密码",i);
        scanf("%d",&password);
        pnew = create_node(i,password);
        if(head==NULL)   //创建无头结点时要进行分类讨论
        {
            head = pnew;//头指针指向第一个结点
            tail = pnew;//尾指针指向第一个结点
        }
        else
        {
            tail->next = pnew;   //尾指针的下一个指向新的结点
            tail = pnew;         //尾指针更新
        }
    }
    tail->next = head;
    printf("完成无头循环的建立");
    return head;
}
int IsEmptyList(Node*head) //判断无头链表是否为空
{
    if(!head)
    {
        printf("This list is empty!");
        return 1;
    }
    return 0;
}

void output(Node*head)  //输出无头链表
{

    Node*pmove = head;
    if(!IsEmptyList)
    {
        printf("--ID-- --PASSWORD--\n");
        do
        {
            printf("%3d %7d\n",pmove->id,pmove->password);
            pmove = pmove->next;
        }while(pmove!=head);
    }

}

void JosephusOperate(Node* head,int firstpassword)
{
    int icounter = 0;  //作用为辅助for循环
    int flag = 1;  //相当于Bool值，进行判断是否全部出队
    Node * tail,*point,*temp;  //tail和point两个指针进行一前一后双指针删除操作
    point = tail = head;     
    while(tail->next!=head)   //tail来指向尾结点
    {
        tail = tail->next;   
    }
    while(flag)    
    {
        for(icounter = 1;icounter<firstpassword;icounter++)   //找到要出队的选手
        {
            tail = point;
            point = point->next;
        }
        if(point == tail) flag = 0;       //两个指针重合，说明队为空
        temp = point;                     //temp来记录要删除的结点
        tail->next = point->next;         //进行删除操作
        point= point->next;
        firstpassword = temp->password;
        printf("第%d个人出列（密码%d）\n",temp->id,temp->password);
        free(temp);
    }

    head = NULL;         // 此时队为空

}

int main()
{
    int n = 0,m = 0;
    printf("请输入人数：");
    scanf("%d",&n);
    printf("请输入初始密码:");
    scanf("%d",&m);
    Node *head = Create_List(n);
    printf("\n------------打印单项循环链表-------------\n");
    output(head);
    printf("\n------------打印出队情况-------------\n");
    JosephusOperate(head,m);
    return 1;
}
