#pragma once

#define MAXSIZE 100

typedef int DataType;

typedef struct
{
	DataType data[MAXSIZE];
	int top;
}seqStack,*pSeqStack;

pSeqStack initSeqStack(void);                //初始化顺序栈
bool isEmptySeqStack(pSeqStack S);           //判断栈是否为空
bool pushSeqStack(pSeqStack S, DataType X);  //入栈
bool popSeqStack(pSeqStack S);               //出栈
DataType getTopSeqStack(pSeqStack S);        //取栈顶元素
void destroySeqStack(pSeqStack *S);          //销毁栈
void printSeqStack(pSeqStack S);			 //打印栈的所有元素