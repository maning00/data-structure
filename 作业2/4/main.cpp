//  设计汉诺塔程序
//  main.cpp
//  4
//
//  Created by 马宁 on 2018/11/21.
//  Copyright © 2018 马宁. All rights reserved.
//
#include <cstdlib>
#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX 100
int num=0;



typedef struct stack {
    int data[MAX];
    int top;
    char flag;
}stack;

void move(stack &a,int n,stack & c, stack &b){
    if(n==1){
        printf("%c移动数据%d到%c\n",a.flag,a.data[a.top],b.flag);
        num++;
        
        b.top++;
        b.data[b.top]=a.data[a.top];
        a.top--;
        
    }
    else{
        move(a,n-1,b,c);
        printf("%c移动数据%d到%c\n",a.flag,a.data[a.top],b.flag);
        num++;
        b.top++;
        b.data[b.top]=a.data[a.top];
        a.top--;
        move(c,n-1,a,b);
    }
}

int main(int argc, char *argv[])
{
    stack a;
    a.top=3;
    a.flag='A';
    for(int i=1;i<=3;i++){
        a.data[i]=4-i;
    }
    stack c;
    c.top=0;
    c.flag='C';
    
    stack b;
    b.top=0;
    b.flag='B';
    
    move(a,4,b,c);
    
    printf("一共移动了%d次\n",num);
    
    for(int i=1;i<=4;i++){
        printf("%d",b.data[i]);
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
