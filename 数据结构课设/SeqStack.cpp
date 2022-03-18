#include<stdio.h>
#include<stdlib.h>
#include"seqStack.h"

//��ʼ��ջ
pSeqStack initSeqStack(void)
{
	pSeqStack S;
	S = (pSeqStack)malloc(sizeof(seqStack));

	if (S != NULL)
		S->top = -1;

	return S;
}

//�ж�ջ�Ƿ�Ϊ��
bool isEmptySeqStack(pSeqStack S)
{
	if (S->top == -1)
		return true;
	else
		return false;
}

//��ջ
bool pushSeqStack(pSeqStack S, DataType X)
{
	if (S->top == MAXSIZE - 1)   //ջ��������ջ
		return false;
	else
	{
		S->top++;
		S->data[S->top] = X;
		return true;
	}
}

//��ջ
DataType popSeqStack(pSeqStack S)
{
	DataType temp = S->data[S->top];
	S->top--;
	return temp;
}

//ȡջ��Ԫ��
DataType getTopSeqStack(pSeqStack S)
{
	if (isEmptySeqStack(S))  //ջ�ղ���ȡջ��Ԫ��
	{
		printf("ջ�գ�û��ջ��Ԫ�أ�");
	}
	else
		return S->data[S->top];
}

//����ջ
void destroySeqStack(pSeqStack* S)
{
	if (*S != NULL)
	{
		free(*S);
		*S = NULL;
	}
}
