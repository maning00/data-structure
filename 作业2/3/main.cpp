//3.    写出求循环队列长度的算法。
//  main.cpp
//  3
//
//  Created by 马宁 on 2018/11/20.
//  Copyright © 2018 马宁. All rights reserved.
//

#include <stdio.h>
#include<cstdio>
#include <iostream>
using namespace std;
int maxsize=11;

struct sequeue
{
    int *data;
    int front;
    int rear;
};

//  初始化循环队列
void Init_sequeue(sequeue *sq,int size)
{
    sq->data=new int[size];
    sq->front=0;
    sq->rear=0;
    
}


//入队
void En_sequeue(sequeue *sq,int data)
{
    if((sq->rear+1)%maxsize==sq->front)
        printf("队满上溢!");
    else
    {
        sq->data[sq->rear]=data;
        sq->rear=(sq->rear+1)%maxsize;
    }
}
//计算队列长度
int cal(sequeue *sq)
{
    int n;
    n = (sq->rear - sq->front + maxsize) % maxsize;
    return n;
}





int main()
{
    
    sequeue *sq;
    int a;
    sq= new sequeue;
    Init_sequeue(sq, maxsize);
part1:printf("请输入数字，按0结束：");
    cin>> a;
    if(a==0)
    {goto part2;}
    else
    {En_sequeue(sq, a);
        goto part1;}

part2:  int c = cal(sq);
    cout << c <<endl;
    return c;
    
}
