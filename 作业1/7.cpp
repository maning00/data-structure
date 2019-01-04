//设计算法，将带头节点的双向循环链表逆置。
// Created by MN on 2018/11/3.
//

#include "stdio.h"
#include "cstdlib"
#include <iostream>
using namespace std;
typedef int ElemType;

typedef struct DNode
{
    ElemType data;
    DNode *prior;
    DNode *next;
}DNode,*LinkList;

DNode *Create_LinkList(ElemType *arr, int n)
{
    DNode *head;
    DNode *p;
    int i;
    p=new (DNode);
    head=p;
    head->prior= head;
    head->next= head;
    ///
    p=new DNode;
    p->data=arr[n-1];
    p->next=head->next;
    p->prior=head;
    head->next=p;
    for (i=n-2;i>=0;i--)
    {
        p=new DNode;
        p->data=arr[i];
        p->next=head->next;
        p->prior=head;
        head->next=p;
        p->next->prior=p;
    }
    return head;
}

DNode *Revert(DNode *head)
{
    DNode *pre,*nex,*cur;
    DNode *p;
    p=head;
    pre=head;
    cur=head->next;
    nex= nullptr;

    while(cur->next!=head->next)
    {
        nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
    }
    head->next = pre;
    return head;
}

void ShowLinkList(DNode *head)
{
    DNode *r = head->next;
    while (r->next != head){
        printf("%d ", r->data);
        r = r->next;
    }
    printf("%d ", r->data);
    printf("\n");
}


int main()
{
    int i;
    printf("please enter seven numbers:");
    ElemType data[7];
    for(i=0;;i++)
    {
        cin>>data[i];
        if(getchar()=='\n') //遇回车结束
            break;
    }
    int length = sizeof(data) / sizeof(ElemType);
    DNode *D=Create_LinkList(data,length);
    ShowLinkList(D);
    DNode *R=Revert(D);
    ShowLinkList(R);
    return 0;
}