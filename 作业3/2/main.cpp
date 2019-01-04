//2.编写算法求一棵二叉树的根节点T到一个指定节点D之间的路径并输出。
//  main.cpp
//  2
//
//  Created by 马宁 on 2018/12/10.
//  Copyright © 2018 马宁. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
#include "math.h"
using namespace std;


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

bool Route(bitreenode *root,int x,vector<int> &v)
{
   if(root==NULL)
   {
       return false;
   }
    v.push_back(root->data);
    bool found=false;
    if(root->data==x)
    {
        found = true;
        for(int i=12;i<v.size();i++)
            cout<<v[i]<<"  ";
        cout<<endl;
    }
    if (!found && root->lchild)
    {
        found=Route(root->lchild, x, v);
    }
    if (!found && root->rchild)
    {
        found=Route(root->rchild, x, v);
    }
    v.pop_back();
    return found;
}

int main(){
    vector<int> a={0,1,2,3,4,5,6,7,8,9,10,11};
    int c[]={0,1,2,3,4,5,6,7,8,9,10,11};
    bitreenode *b = Creat_bitreeLinklist(12,c);
    Route(b,11,a);
    return 0;
}
