//已知带头节点的单链表中的节点的值是非递减有序的（允许值相同），编写算法实现将值X插入到该链表中，是该链表仍然有序。
// Created by MN on 2018/11/2.
//

#include "stdio.h"
#include "cstdlib"
#include <iostream>
using namespace std;
typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    LNode *next;
}LNode,*LinkList;


LNode *Create_LinkList(ElemType *arr, int n)
{
    LNode *head;
    LNode *p;
    int i;
    p=new (LNode);
    head=p;
    head->next= nullptr;
    for (i = n-1; i >= 0; i--)
    {
        p = (LNode *)malloc(sizeof(LNode));
        p->data = arr[i];
        p->next = head->next;
        head->next = p;
    }
    return head;
}


void ShowList(LNode *head)
{
    LNode *r = head->next;
    while (r->next != nullptr){
        printf("%d ", r->data);
        r = r->next;
    }
    printf("%d ", r->data);
    printf("\n");
}

int Link_list_order_check(LNode *head)
{
    LNode *p,*q;
    for(p=head;p->next;p=p->next)
    {
        for(q=p->next;q->next;q=q->next)
        {
            if(p->next->data>q->next->data)
            {
                printf("输入的链表不是非递减有序的！请重新输入。\n");

                return 1;                                            //将输入参数不合法反映到上级函数
            }
        }
    }
    return 0;
}

LNode *Link_list_insert_order(LNode *head,int x)
{
    LNode *p,*q;
        p=new(LNode);
        p->data=x;
        for(q=head;q->next&&q->next->data<x;q=q->next);
        p->next=q->next;
        q->next=p;

    return head;
}


int main()
{
    int x;
    //ElemType data[7] = {1, 3, 3, 7, 9, 11, 13};//测试数据
    ElemType data[5];
    int i;
    L1: printf("请输入5个数据，以空格隔开:");

    for(i=0;;i++)
    {
        cin>>data[i];
        if(getchar()=='\n') //遇回车结束
            break;
    }
    int length = sizeof(data) / sizeof(ElemType);
    LNode *L = Create_LinkList(data, length);
    while(Link_list_order_check(L)==1)
        goto L1;
    printf("单链表\nBefore:");
    ShowList(L);
    printf("请输入插入值：");
    scanf("%d",&x);
    Link_list_insert_order(L,x);
    printf("After:");
    ShowList(L);
}