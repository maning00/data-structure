//分别将顺序表和单链表实现就地逆置，要求利用原表的存储空间将线性表（a1,a2,a3,…,an）变为（an,…,a3,a2,a1）。

#include<stdio.h>
#include <cstdlib>
typedef int ElemType;

typedef struct {
    ElemType data[10];
    int length;
}sxb;
void Reverse(sxb*,int,int,int);
void Print(sxb*);

/*int main()
{

}*/

void Reverse(sxb *L,int Left, int Right,int length){
    ElemType temp;
    int mid;
    mid=(Left+Right)/2;
    for (int i=0;i<mid-Left;i++){
        temp=L->data[Left+i];
        L->data[Left+i]=L->data[Right-i];
        L->data[Right-i]=temp;
    }
}

void Print(sxb *L){
    for(int i=0;i<L->length;i++){
        printf("%4d",L->data[i]);
    }
    printf("\n");
}



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

LNode *Reverse(LNode *head)
{
    if (head->next == nullptr)
        printf("只有一个首节点");
    if (head->next->next == nullptr)
        printf("无需逆置");

    LNode *last,*pre,*cur,*nex;
    last = head->next;
    pre = head;
    cur = head->next;
    nex = nullptr;

    while(cur)
    {
        nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
    }
    last->next = nullptr;
    head->next = pre;
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



int main() {
    sxb bb;
    bb.length = 10;
    for (int i = 0; i < bb.length; i++) {
        bb.data[i] = i + 1;
    }
    printf("顺序表：\n");
    Print(&bb);
    Reverse(&bb, 0, bb.length - 1, bb.length - 1);
    Print(&bb);

    ElemType data[7] = {1, 2, 3, 4, 5, 6, 7};//测试数据
    int length = sizeof(data) / sizeof(ElemType);
    LNode *L = Create_LinkList(data, length);
    printf("单链表\nBefore:");
    ShowList(L);
    Reverse(L);
    printf("After:");
    ShowList(L);


    return 0;
}


//
// Created by MN on 2018/10/29.
//

