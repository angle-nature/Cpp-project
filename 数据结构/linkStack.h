#pragma once
#include"TempBiTree.h"

typedef int DataType;

struct Stack
{
	DataType data;
	Stack* next;
};

typedef Stack linkStack;
typedef Stack* pLinkStack;

pLinkStack initLinkStack(void);                    //初始化栈
bool isEmptyLinkStack(pLinkStack S);               //判断栈是否为空
bool pushLinkStack(pLinkStack S, DataType X);      //入栈
bool popLinkStack(pLinkStack S);                   //出栈
DataType getTopLinkStack(pLinkStack S);            //取栈顶元素
void destroyLinkStack(pLinkStack S);               //销毁栈
void printLinkStack(pLinkStack S);                 //打印栈中的所有元素