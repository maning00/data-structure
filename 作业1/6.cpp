//将带头节点的双向循环链表为（a1,a2,a3,a4,…,an）,编写一个时间复杂度为O(n)的算法。将该链表改造成（a1,a3,a5,…,an,…,a4,a2）
// Created by MN on 2018/10/31.
//
#include <cstdlib>
#include<stdio.h>
#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct DuLNode{
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
} DuLNode, *DuLinkList;

DuLinkList InitDuLinkList();//初始化双向循环链表(头节点)
void CreateDuLinkList(DuLinkList L, ElemType *arr, int n);//创建链表元素
void ShowList(DuLinkList L);//输出链表

/*
将L中的元素，按如下规则插入新表，并返回新表。
（1,2）->(1,3,2)->(1,3,4,2)->(1,3,5,4,2)->(1,3,5,6,4,2)->...
*/
DuLinkList Transform(DuLinkList L);

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
    //ElemType data[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };//测试数据2（偶数个）
    int length = sizeof(data) / sizeof(ElemType);
    DuLinkList L = InitDuLinkList(), Lnew;
    CreateDuLinkList(L, data, length);
    printf("Before:");
    ShowList(L);

    Lnew = Transform(L);
    printf("After:");
    ShowList(Lnew);

    return 0;
}


DuLinkList InitDuLinkList()
{
    DuLNode *dnode = (DuLNode *)malloc(sizeof(DuLNode));
    dnode->data = 0;
    dnode->prior = dnode;
    dnode->next = dnode;
    return dnode;
}

void CreateDuLinkList(DuLinkList L, ElemType *arr, int n)
{
    DuLNode *dnode;
    DuLNode *p = L;
    int i;
    for (i = 0; i < n; i++)
    {
        dnode = (DuLNode *)malloc(sizeof(DuLNode));
        dnode->data = arr[i];
        dnode->next = L;
        dnode->prior = p;
        p->next = dnode;
        p = p->next;
    }
}

void ShowList(DuLinkList L)
{
    int i;
    DuLNode *r = L->next;
    while (r->next != L){
        printf("%d ", r->data);
        r = r->next;
    }
    printf("%d ", r->data);
    printf("\n");
}

DuLinkList Transform(DuLinkList L)
{
    DuLinkList Lnew = InitDuLinkList();
    DuLNode *p, *q, *pa, *pb;
    q = p = L->next;
    pa = pb = Lnew;

    while (p != L)
    {
        if (p != L)
        {
            /*L中寄数个数据插入Lnew*/
            q = p->next;//保留 L 链表
            //pa之后插入p
            p->prior = pa;
            pa->next = p;
            p->next = pb;
            pb->prior = p;

            pa = pa->next;
            p = q;//p指向 待操作 L
        }
        if (p != L)
        {
            /*L中偶数个数据插入Lnew*/
            q = p->next;//保留 L 链表
            //pb之前插入p
            p->next = pb;
            pb->prior = p;
            p->prior = pa;
            pa->next = p;

            pb = pb->prior;
            p = q;//p指向 待操作 L
        }
    }
    return Lnew;
}