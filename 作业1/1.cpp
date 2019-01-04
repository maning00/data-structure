//将顺序表的前m个元素和后n个元素进行整体互换，即将线性表（a1,a2,a3,…,am,b1,b2,b3,…,bn）改变为（b1,b2,b3,…,bn,a1,a2,a3,…,am）
// Created by MN on 2018/10/29.
//
#include<stdio.h>
#include <cstdlib>
typedef int ElemType;

typedef struct {
    ElemType data[10];
    int length;
}sxb;
void Reverse(sxb*,int,int);
void Print(sxb*);

int main()
{
    sxb bb;
    bb.length=10;
    for (int i=0;i<bb.length;++i){
        bb.data[i]=i+1;
    }
    int m=4,n=bb.length-m;
    Print(&bb);
    Reverse(&bb, 0, bb.length-1);
    Reverse(&bb, 0, n-1);
    Reverse(&bb, n, bb.length-1);
    Print(&bb);
    return 0;
}

void Reverse(sxb *L,int Left, int Right){
    ElemType temp;
    int mid;
    mid=(Left+Right)/2;
    for (int i=0;i<= mid-Left;i++){
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
