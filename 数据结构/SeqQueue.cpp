#include<stdio.h>
#include<stdlib.h>
#include"SeqQueue.h"

//��ʼ��˳�����
pSeqQueue initSeqQueue()
{
	pSeqQueue Q = (pSeqQueue)malloc(sizeof(seqQueue));

	if (Q == NULL)
		printf("ջ�����");
	else
		Q->front = Q->rear = 0;

	return Q;
}

//�ж�˳������Ƿ�Ϊ��
bool isEmptySeqQueue(pSeqQueue Q)
{
	if (Q->front == Q->rear)
		return true;
	else
		return false;
}

//���
bool inSeqQueue(pSeqQueue Q, DataType X)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)  //ѭ������ ����Ҫ����ȡģ����(����)
		return false;
	else
	{
		Q->rear = (Q->rear + 1) % MAXSIZE;
		Q->data[Q->rear] = X;
		return true;
	}	
}

//����
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

//��ȡ��ͷԪ��
DataType frontSeqQueue(pSeqQueue Q)
{
	if (isEmptySeqQueue(Q))
	{
		printf("�ӿ�!");
		return 0;
	}

	else
	{
		return Q->data[(Q->front+1)%MAXSIZE];
	}
}

//����˳�����
void destorySeqQueue(pSeqQueue Q)
{
	if (Q != NULL)	
		free(Q);
}

//��������е�����Ԫ��
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