#pragma once

#define MAXSIZE 100
typedef int DataType;

typedef struct
{
	DataType data[MAXSIZE];
	int front, rear;
}seqQueue,*pSeqQueue;

pSeqQueue initSeqQueue();                        //��ʼ��˳�����
bool isEmptySeqQueue(pSeqQueue Q);               //�ж�˳������Ƿ�Ϊ��
bool inSeqQueue(pSeqQueue Q, DataType X);        //���
bool outSeqQueue(pSeqQueue Q);                   //����
DataType frontSeqQueue(pSeqQueue Q);             //��ȡ��ͷԪ��
void destorySeqQueue(pSeqQueue Q);               //����˳�����
void printSeqQueue(pSeqQueue Q);                 //��������е�����Ԫ��