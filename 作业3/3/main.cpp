//3.编写算法求一棵二叉树的深度。
//  main.cpp
//  3
//
//  Created by 马宁 on 2018/12/10.
//  Copyright © 2018 马宁. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int maxsize=50;


struct bitreenode
{
    int data;
    bitreenode *lchild,*rchild;
};



struct seqstack
{
    bitreenode data[15];
    int top;
};
struct seqstackag
{
    int data[13];
    int top;
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

bitreenode Pop_Stack(seqstack *s)
{
    bitreenode data,zero;
    zero.data=NULL;
    zero.lchild=nullptr;
    zero.rchild=nullptr;
    if(s->top<0)
    {printf("栈空！");
        return zero;
    }
    else
    {
        data=s->data[s->top];
        s->top=s->top-1;
    }
    return data;
}


int depth(bitreenode *root)
{
    if (root == NULL)
        return 0;
    if (root->lchild == NULL && root->rchild == NULL)
        return 1;
    queue<bitreenode *> nodes;
    nodes.push(root);
    int d=0;
    while (!nodes.empty()) {
        queue<bitreenode*> q;
        
        while (!nodes.empty()) {
            bitreenode *tmp;
            tmp = new bitreenode;
            tmp=nodes.front();
            nodes.pop();
            
            if (tmp->lchild != NULL) {
                q.push(tmp->lchild);
            }
            if (tmp->rchild != NULL) {
                q.push(tmp->rchild);
            }
            
        }
        ++d;
        nodes=q;
    }
    return d;
}

int main(){
    int a[]={0,1,2,3,4,5,6,7,8,9,10,11};
    bitreenode *b = Creat_bitreeLinklist(12,a);
    cout<<depth(b)<<endl;;
    return 0;
}
