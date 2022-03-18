#include<stdio.h>
#include<stdlib.h>
#include"seqStack.h"

//初始化栈
pSeqStack initSeqStack(void)
{
	pSeqStack S;
	S = (pSeqStack)malloc(sizeof(seqStack));

	if (S != NULL)
		S->top = -1;

	return S;
}

//判断栈是否为空
bool isEmptySeqStack(pSeqStack S)
{
	if (S->top == -1)
		return true;
	else
		return false;
}

//入栈
bool pushSeqStack(pSeqStack S, DataType X)
{
	if (S->top == MAXSIZE - 1)   //栈满不能入栈
		return false;
	else
	{
		S->top++;
		S->data[S->top] = X;
		return true;
	}
}

//出栈
DataType popSeqStack(pSeqStack S)
{
	DataType temp = S->data[S->top];
	S->top--;
	return temp;
}

//取栈顶元素
DataType getTopSeqStack(pSeqStack S)
{
	if (isEmptySeqStack(S))  //栈空不能取栈顶元素
	{
		printf("栈空，没有栈顶元素！");
	}
	else
		return S->data[S->top];
}

//销毁栈
void destroySeqStack(pSeqStack* S)
{
	if (*S != NULL)
	{
		free(*S);
		*S = NULL;
	}
}
