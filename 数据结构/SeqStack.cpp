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
bool popSeqStack(pSeqStack S)
{
	if (isEmptySeqStack(S))  //ջ�ղ��ܳ�ջ
		return false;
	else
	{
		S->top--;
		return true;
	}
}

//ȡջ��Ԫ��
DataType getTopSeqStack(pSeqStack S)
{
	if (isEmptySeqStack(S))  //ջ�ղ���ȡջ��Ԫ��
	{
		printf("ջ�գ�û��ջ��Ԫ�أ�");
		return 0;
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

//��ӡջ������Ԫ��
void printSeqStack(pSeqStack S)
{
	for (int i = S->top; i >=0; i--)
	{
		printf("%d ", S->data[i]);
		
		if (i % 9 == 0 && i != 0)
			putchar('\n');
	}
	putchar('\n');
}