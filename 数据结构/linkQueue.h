#pragma once
typedef int DataType;

typedef struct Qnode
{
	DataType data;
	Qnode *next;
}qNode,*pQNode;

typedef struct
{
	pQNode front,rear;
}linkQueue,*pLinkQueue;

pLinkQueue initLinkQueue();                        //��ʼ����ʽ����
bool isEmptyLinkQueue(pLinkQueue Q);               //�ж���ʽ�����Ƿ�Ϊ��
bool inLinkQueue(pLinkQueue Q, DataType X);        //���
bool outLinkQueue(pLinkQueue Q);                   //����
DataType frontLinkQueue(pLinkQueue Q);             //��ȡ��ͷԪ��
void destoryLinkQueue(pLinkQueue Q);               //������ʽ����
void printLinkQueue(pLinkQueue Q);                 //��������е�����Ԫ��