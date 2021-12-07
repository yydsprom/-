#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode
{
    int val;
    struct ListNode *next;
}ListNode;


ListNode * reverse(ListNode * head)   //一个一head整表翻转链表
{   
    ListNode * pre = NULL;   //技巧1：快慢指针
    ListNode * curr = head;
    ListNode * next = NULL;
    while(curr != NULL)
    {
        next =curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    return pre;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
//技巧2：添加dummy，构建虚假链表头
    ListNode * dummy = (ListNode*)malloc(sizeof(ListNode));
    dummy->next = head;

    //一共创建四个指针分别为pre--next，start--end
    ListNode *pre=dummy,*start = head,*end = head,*next = head;
   
    while(next !=NULL)
    {
        //归置end,next
        for(int i = 1;i<k&&end!=NULL;i++)
        {
            end = end->next;
        }
        if(end == NULL)
            break;
        next = end->next;
        end->next = NULL;

        //到这里归置好了pre，next，start，end

        end = start;
        start = reverse(start);
        end->next = next;
        pre->next = start;

        //以上就连接好啦链表

        

        //归置 pre,start
        pre = end;
        start = next;
        end = start;
        



    }


     return dummy->next;
}