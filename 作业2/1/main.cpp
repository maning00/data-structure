//1.    设计算法判断一个算术表达式中的圆括号能否正确配对。
//  main.cpp
//  homework2
//
//  Created by 马宁 on 2018/11/13.
//  Copyright © 2018 马宁. All rights reserved.
//

#include <iostream>
#include<cstdio>
#include <string>
using namespace std;
int maxsize=10;
int cc=1;


struct seqstack
{
    int data[10];
    int top;
};

void Init_stack(seqstack *s)
{
    s->top=-1;
}


void  Push_Stack(seqstack *s,int x)
{
    if(s->top==maxsize-1) printf("溢出");
    else
    {
        s->top=s->top+1;
        s->data[s->top]=x;
    }
}


int Pop_Stack(seqstack *s)
{
    int data;
    if(s->top<0)
    {printf("栈空！\n");
        cc=0;
        return NULL;
    }
    else
    {
        data=s->data[s->top];
        s->top=s->top-1;
    }
    return (data);
}

int Detect_Stack(seqstack *s)
{
    if (cc==0)
        return 0;
    else if (s->top<0)
        return 1;
    else
        return 0;
    
}

int main()
{
//    char* expression = nullptr;
    string exp;
    printf("请输入表达式：");
    cin >> exp;
    char* expression = (char*)exp.c_str();
//    printf("请输入表达式：");
//    scanf("%s",&*expression);
 
    int length=exp.length();
//    cout<<length;
    bool islegal = false;
    seqstack *bracketsStack = nullptr;
    bracketsStack = new (seqstack);
    Init_stack(bracketsStack);
    for(int i = 0; i < length; i++)
    {
        if(expression[i]== '(')
        {
            Push_Stack(bracketsStack, i);
        }

    
        if(expression[i] == ')')
        {
            Pop_Stack(bracketsStack);
    
        }
    }
    int dd=Detect_Stack(bracketsStack);
    
    if (dd==1) {
        islegal = true;
        printf("正确配对\n");
    }
    else
        printf("配对错误\n");
    return islegal;
}

