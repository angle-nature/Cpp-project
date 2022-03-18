#include<stdio.h>
#include<stdlib.h>
#include"linkQueue.h"

//初始化链式队列
pLinkQueue initLinkQueue()
{
	pLinkQueue Q = (pLinkQueue)malloc(sizeof(linkQueue));

	if (Q == NULL)
		printf("内存不足！");
	else
	{
		Q->front = NULL;
		Q->rear = NULL;
	}

	return Q;
}

//判断链式队列是否为空
bool isEmptyLinkQueue(pLinkQueue Q)
{
	if (Q->front == NULL)
		return true;
	else
		return false;
}

//入队
bool inLinkQueue(pLinkQueue Q, DataType X)
{
	pQNode p = (pQNode)malloc(sizeof(qNode));
	if (p == NULL)
	{
		printf("内存不足!\n");
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

//出队
bool outLinkQueue(pLinkQueue Q)
{
	pQNode p;
	if (isEmptyLinkQueue(Q))
	{
		printf("队列空!!\n ");
		return false;
	}
	
	p = Q->front;
	Q->front = Q->front->next;

	free(p);

	if (Q->front == NULL)
		Q->rear = NULL;

	return true;
	
}

//读取队头元素
DataType frontLinkQueue(pLinkQueue Q)
{
	if (Q->front != NULL)
		return Q->front->data;
}

//销毁链式队列
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

//输出队列中的所有元素
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