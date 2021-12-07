#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int num;
    char name[20];
    int score;
    struct Node *next;
}*LPnode,node;

LPnode Create()
{
    int x;
    LPnode head = (LPnode)malloc(sizeof(node));
    head->next=NULL;
    LPnode tail = head,p;
    scanf("%d",&x);
    while(x)
    {
        p =  (LPnode)malloc(sizeof(node));
        p->next = NULL;
        p->num = x;
        gets(p->name);
        scanf("%d",p->score);
        tail->next = p;
        tail = p;
        scanf("%d",&x);
    }
    tail->next = NULL;
    return head;
}

LPnode Delete(LPnode head,int min)
{
    LPnode p=head->next,pre=head,q;
    while(p != NULL)
    {
        if(p->score<min)
        {
            q = p;
            p = p->next;
            pre->next = p;
            free(p);
        }
        else
        {
            pre= p;
            p = p->next;
        }

    }

    return head;

}


void Print(LPnode head)
{
    LPnode p;
    for(p = head->next;p!=NULL;p=p->next)
    {
           printf("%d %s %d\n",p->num,p->name,p->score);


    }

}

int main()
{
    LPnode head;
    head = Create();
    int socre;
    scanf("%d",&socre);
    head = Delete(head,socre);
    Print(head);
    return 0;


}