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

pLinkQueue initLinkQueue();                        //初始化链式队列
bool isEmptyLinkQueue(pLinkQueue Q);               //判断链式队列是否为空
bool inLinkQueue(pLinkQueue Q, DataType X);        //入队
bool outLinkQueue(pLinkQueue Q);                   //出队
DataType frontLinkQueue(pLinkQueue Q);             //读取队头元素
void destoryLinkQueue(pLinkQueue Q);               //销毁链式队列
void printLinkQueue(pLinkQueue Q);                 //输出队列中的所有元素