//设计算法判断一个算术表达式中的圆括号，中括号，大括号能否正确配对，并计算每种括号配对的个数。
//  main.cpp
//  2
//
//  Created by 马宁 on 2018/11/20.
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
    int xcount=0;
    int zcount=0;
    int dcount=0;
    int zb = 0;    //用于存放左小括号数
    int zz = 0;    //左中
    int zd = 0;    //左大
    seqstack *bracketsStack = nullptr;
    seqstack *zhongstack = nullptr;
    seqstack *dastack = nullptr;
    bracketsStack = new (seqstack);
    zhongstack = new (seqstack);
    dastack = new (seqstack);
    Init_stack(bracketsStack);
    Init_stack(zhongstack);
    Init_stack(dastack);
    for(int i = 0; i < length; i++)
    {
        if(expression[i]== '(')
        {
            Push_Stack(bracketsStack, i);
            zb = zb+1;
        }
        if (expression[i]=='[') {
            Push_Stack(zhongstack, i);
            zz = zz +1;
        }
        if (expression[i]=='{') {
            Push_Stack(dastack, i);
            zd = zd + 1;
        }
        
        if(expression[i] == ')')
        {
            Pop_Stack(bracketsStack);
          
            if (zb>0) {
                xcount=xcount+1;
            }
            
        }
        
        if (expression[i]==']') {
            Pop_Stack(zhongstack);

            if (zz>0){
                zcount=zcount+1;
            }
            
        }
        
        if (expression[i]=='}') {
            Pop_Stack(dastack);
           
            if (zd>0) {
                dcount = dcount+1;
            }
            
        }
        
        
    }
    int dd=Detect_Stack(bracketsStack) && Detect_Stack(zhongstack) && Detect_Stack(dastack);
    
    if (dd==1) {
        islegal = true;
        printf("正确配对\n");
        cout << "小括号配对数为：" << xcount <<endl;
        cout << "中括号配对数为：" << zcount <<endl;
        cout << "大括号配对数为：" << dcount <<endl;
    }
    else
        printf("存在配对错误\n");
        cout << "小括号配对数为：" << xcount <<endl;
        cout << "中括号配对数为：" << zcount <<endl;
        cout << "大括号配对数为：" << dcount <<endl;
    return islegal;
}
