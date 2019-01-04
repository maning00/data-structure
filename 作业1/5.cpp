//编写用带头指针的单循环链表和用尾指针表示的单循环链表上实现将两个线性表连接成一个线性表。
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


LNode *Create_Rear_Circular_LinkList(ElemType *arr, int n)
{
    LNode *rear;
    LNode *p;
    int i;
    p=new (LNode);
    rear=p;
    rear->next= rear;
    rear->data=arr[n-1];
    for(i=n-2;i>=0;i--)
    {
        p=new(LNode);
        p->data=arr[i];
        p->next=rear->next;
        rear->next=p;
    }
    return rear;
}

LNode *Create_Head_Circular_LinkList(ElemType *arr, int n)
{
    LNode *head;
    LNode *p;
    int i;
    p=new (LNode);
    head=p;
    head->next= head;
    for (i = n-1; i >= 0; i--)
    {
        p = (LNode *)malloc(sizeof(LNode));
        p->data = arr[i];
        p->next = head->next;
        head->next = p;
    }
    return head;
}






LNode *link_rear_head_circular_linklist(LNode *rear, LNode *head)
{
    LNode *rear1;
    for(rear1=head;rear1->next!=head;rear1=rear1->next);
    rear1->next=rear->next;
    rear->next=head;
    return  rear;
}

void ShowHeadList(LNode *head)
{
    LNode *r = head->next;
    while (r->next != head){
        printf("%d ", r->data);
        r = r->next;
    }
    printf("%d ", r->data);
    printf("\n");
}

void ShowRearList(LNode *rear)
{
    LNode *r = rear->next;
    while (r->next != rear->next){
        printf("%d ", r->data);
        r = r->next;
    }
    printf("%d ", r->data);
    printf("\n");
}

int main() {
    int x;
    int i;
    printf("请输入7个数组成头指针单循环链表:");
    ElemType data1[7];
    for(i=0;;i++)
    {
        cin>>data1[i];
        if(getchar()=='\n') //遇回车结束
            break;
    }

    printf("请输入7个数组成尾指针单循环链表:");
    ElemType data2[7];
    for(x=0;;x++)
    {
        cin>>data2[x];
        if(getchar()=='\n') //遇回车结束
            break;
    }
    // ElemType data1[7] = {1, 3, 3, 7, 9, 11, 12};//测试数据
    int length1 = sizeof(data1) / sizeof(ElemType);
    //ElemType data2[7] = {13, 15, 16, 17, 18, 19, 21};//测试数据
    int length2 = sizeof(data2) / sizeof(ElemType);
    LNode *H = Create_Head_Circular_LinkList(data1, length1);
    LNode *R = Create_Rear_Circular_LinkList(data2, length2);
    printf("头指针单循环链表：\n");
    ShowHeadList(H);
    printf("尾指针单循环链表：\n");
    ShowRearList(R);
    LNode *L = link_rear_head_circular_linklist(R, H);
    printf("连接后：\n");
    ShowRearList(L);
    return 0;
}
