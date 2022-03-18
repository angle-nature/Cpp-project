#include<stdio.h>
#include<stdlib.h>
#include"SeqList.h"

//构造一个空线性表
pSeqList initSeqList(void)
{
	pSeqList p = (pSeqList)malloc(sizeof(seqList));
	if (p != NULL)
		p->length = 0;
	return p;
}

//求长度
int lengthSeqList(pSeqList L)
{
	return L->length;
}

//检索操作
int locationSeqlist(pSeqList L, DataType X)
{
	int i = 0;

	while (i<L->length&&L->data[i]!=X)
	{
		i++;
		if (i >= L->length)
			return false;
		else
			return (i + 1);
	}
}

//插入元素
bool insertSeqList(pSeqList L, DataType X, int i)
{
	if (L == NULL||L->length>=MAXSIZE||i<1||i>L->length+1)	
		return false;
	else
	{
		for (int j = L->length - 1; j >= i - 1; j--)
			L->data[j + 1] = L->data[j];
		L->data[i - 1] = X;
		L->length++;
		return true;
	}
}

//删除顺序表元素
int daleteSeqList(pSeqList L,int i)
{
	if (L == NULL || i<1 || i>L->length)
		return false;
	else
	{
		for (int j = i; j < L->length; j++)
			L->data[j - 1] = L->data[j];
		L->length--;
		return true;
	}
}