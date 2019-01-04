//请打印输出杨辉三角的图案（要求：使用循环队列）
//  main.cpp
//  5
//
//  Created by 马宁 on 2018/11/21.
//  Copyright © 2018 马宁. All rights reserved.
//

#include <stdio.h>
#include<cstdio>
#include <iostream>

#define Maxsize 100

typedef struct NODE
{
    int data[Maxsize];
    int rear;
    int front;
}CqQueue, *sequeue;

/*
 函数功能：队列的初始化
 */
sequeue Init_sequeue(sequeue Queue)
{
    Queue = (sequeue)malloc(sizeof(CqQueue));
    if (!Queue)
    {
        printf("Memory allocation is failure!\n");
    }
    Queue->front = 0;
    Queue->rear = 0;
    
    return Queue;
}
/*
 函数功能：从队头删除元素
 */
sequeue Del_sequeue(sequeue Queue, int *temp)
{
    if (Queue->rear == Queue->front)
        return Queue;
    Queue->front = (Queue->front + 1) % Maxsize;//(Queue->front + 1)%Maxsize, (Queue->rear + 1) % Maxsize; 形成循环队列
    *temp = Queue->data[Queue->front];
    Queue->data[Queue->front] = 0;
    
    return Queue;
}
/*
 函数功能：查找队头元素
 */
sequeue Get_Head_sequeue(sequeue Queue, int *x)
{
    if (Queue->rear == Queue->front)
        return Queue;
    *x = Queue->data[(Queue->front + 1) % Maxsize];
    
    return Queue;
}
/*
 函数功能：从队尾插入元素
 */
sequeue En_sequeue(sequeue Queue, int e)
{
    Queue->rear = (Queue->rear + 1) % Maxsize;
    if (Queue->rear == Queue->front)
        printf ("The queue is full !");
    else
        Queue->data[Queue->rear] = e;
    
    return Queue;
}
/*
 函数功能：打印杨辉三角
 */
void PascalTriangle(sequeue Queue, int len)
{
    int temp, x, L, n,y;
    
    Queue = Init_sequeue(Queue);
    Queue = En_sequeue(Queue, 1);
    for (n=2; n<=len; n++)
    {
        for(y=0;y<len+1-n;y++)
            printf("  ");
        Queue = En_sequeue(Queue, 1);
        for (L=1; L<=n-2; L++)
        {
            
            Queue = Del_sequeue(Queue, &temp);
            
            printf("%d   ", temp);
            Queue = Get_Head_sequeue(Queue, &x);
            temp = temp + x;
            Queue = En_sequeue(Queue, temp);
        }
        Queue = Del_sequeue(Queue, &temp);
        printf("%d   ", temp);
        printf("\n");
        Queue = En_sequeue(Queue, 1);
    }
    while (Queue->rear != Queue->front)
    {
        Queue = Del_sequeue(Queue, &temp);
        printf("%d   ", temp);
    }
    printf("\n");
}


int main(void)
{
    sequeue Queue;
    int len;
    
    printf("请输入杨辉三角的行数:\n");
    scanf ("%d" , &len);
    PascalTriangle(Queue, len);
    
    return 0;
}
