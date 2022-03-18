#include<stdio.h>
#include<stdlib.h>
#include"SeqQueue.h"

//初始化顺序队列
pSeqQueue initSeqQueue()
{
	pSeqQueue Q = (pSeqQueue)malloc(sizeof(seqQueue));

	if (Q == NULL)
		printf("栈溢出！");
	else
		Q->front = Q->rear = 0;

	return Q;
}

//判断顺序队列是否为空
bool isEmptySeqQueue(pSeqQueue Q)
{
	if (Q->front == Q->rear)
		return true;
	else
		return false;
}

//入队
bool inSeqQueue(pSeqQueue Q, DataType X)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)  //循环队列 故需要进行取模运算(队满)
		return false;
	else
	{
		Q->rear = (Q->rear + 1) % MAXSIZE;
		Q->data[Q->rear] = X;
		return true;
	}	
}

//出队
bool outSeqQueue(pSeqQueue Q)
{
	if (isEmptySeqQueue(Q))
		return false;
	else
	{
		Q->front = (Q->front + 1) % MAXSIZE;
		return true;
	}

}

//读取队头元素
DataType frontSeqQueue(pSeqQueue Q)
{
	if (isEmptySeqQueue(Q))
	{
		printf("队空!");
		return 0;
	}

	else
	{
		return Q->data[(Q->front+1)%MAXSIZE];
	}
}

//销毁顺序队列
void destorySeqQueue(pSeqQueue Q)
{
	if (Q != NULL)	
		free(Q);
}

//输出队列中的所有元素
void printSeqQueue(pSeqQueue Q)
{
	int index = (Q->front + 1) % MAXSIZE;

	while (index != Q->rear+1)
	{
		printf("%d ", Q->data[index]);
		index = (index + 1) % MAXSIZE;
	}

	putchar('\n');
}