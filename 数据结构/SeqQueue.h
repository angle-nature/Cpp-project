#pragma once

#define MAXSIZE 100
typedef int DataType;

typedef struct
{
	DataType data[MAXSIZE];
	int front, rear;
}seqQueue,*pSeqQueue;

pSeqQueue initSeqQueue();                        //初始化顺序队列
bool isEmptySeqQueue(pSeqQueue Q);               //判断顺序队列是否为空
bool inSeqQueue(pSeqQueue Q, DataType X);        //入队
bool outSeqQueue(pSeqQueue Q);                   //出队
DataType frontSeqQueue(pSeqQueue Q);             //读取队头元素
void destorySeqQueue(pSeqQueue Q);               //销毁顺序队列
void printSeqQueue(pSeqQueue Q);                 //输出队列中的所有元素