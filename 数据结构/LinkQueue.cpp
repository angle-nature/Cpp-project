#include<stdio.h>
#include<stdlib.h>
#include"linkQueue.h"

//��ʼ����ʽ����
pLinkQueue initLinkQueue()
{
	pLinkQueue Q = (pLinkQueue)malloc(sizeof(linkQueue));

	if (Q == NULL)
		printf("�ڴ治�㣡");
	else
	{
		Q->front = NULL;
		Q->rear = NULL;
	}

	return Q;
}

//�ж���ʽ�����Ƿ�Ϊ��
bool isEmptyLinkQueue(pLinkQueue Q)
{
	if (Q->front == NULL)
		return true;
	else
		return false;
}

//���
bool inLinkQueue(pLinkQueue Q, DataType X)
{
	pQNode p = (pQNode)malloc(sizeof(qNode));
	if (p == NULL)
	{
		printf("�ڴ治��!\n");
		return false;
	}
	
	p->data = X;
	p->next = NULL;

	if (isEmptyLinkQueue(Q))	
		Q->rear = Q->front = p;
	
	else
	{
		Q->rear->next = p;		
		Q->rear = p;
	}
	return true;
}

//����
bool outLinkQueue(pLinkQueue Q)
{
	pQNode p;
	if (isEmptyLinkQueue(Q))
	{
		printf("���п�!!\n ");
		return false;
	}
	
	p = Q->front;
	Q->front = Q->front->next;

	free(p);

	if (Q->front == NULL)
		Q->rear = NULL;

	return true;
	
}

//��ȡ��ͷԪ��
DataType frontLinkQueue(pLinkQueue Q)
{
	if (Q->front != NULL)
		return Q->front->data;
}

//������ʽ����
void destoryLinkQueue(pLinkQueue Q)
{
	if (!isEmptyLinkQueue(Q))
	{
		pQNode p;

		while (Q->front != NULL)
		{
			p = Q->front;
			Q->front = Q->front->next;
			free(p);
		}
		free(Q);
	}
}

//��������е�����Ԫ��
void printLinkQueue(pLinkQueue Q)
{
	pQNode p = Q->front;

	while (p !=NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}

	putchar('\n');
}