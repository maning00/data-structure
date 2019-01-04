//4.编写对二叉树按层次遍历的算法。
//  main.cpp
//  4
//
//  Created by 马宁 on 2018/12/10.
//  Copyright © 2018 马宁. All rights reserved.
//

#include <iostream>
#include <queue>
#include "math.h"
using namespace std;
int maxsize=50;


struct bitreenode
{
    int data;
    bitreenode *lchild,*rchild;
};

bitreenode *Creat_bitreeLinklist(int n,int a[])
{
    int i;
    bitreenode *T,*p,*A[32];
    for(i=1;i<=n;i++)
    {
        if(a[i]!=0)
        {
            p=new(bitreenode);
            p->lchild=NULL;
            p->rchild=NULL;
            p->data=a[i];
            ///
            A[i]=p;//向非空的节点中赋值
            if(i==1) T=p;//根
            else{
                if(i%2==0) A[i/2]->lchild=p;
                else A[i/2]->rchild=p;
            }
        }
    }
    return T;
}


void depth(bitreenode *root)
{
    int count=0;
    queue<bitreenode *> q;
    bitreenode *p=root;
    if(p!=NULL){
        q.push(p);
    }
    while (!q.empty()) {
        p = q.front();
        q.pop();
        
        if (p->lchild != NULL) {
            q.push(p->lchild);
        }
        if (p->rchild != NULL) {
            q.push(p->rchild);
        }
        if (p->lchild==NULL && p->rchild==NULL) {
            count++;
        }
        
    }
    cout<<"叶子数为"<<count;
}


int main(){
    int a[]={0,1,2,3,4,5,6,7,8,9,10};
    bitreenode *b = Creat_bitreeLinklist(11,a);
    depth(b);
    return 0;
}
