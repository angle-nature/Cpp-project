#pragma once

#define MAXSIZE 100

typedef int DataType;

typedef struct 
{
	DataType data[MAXSIZE];
	int length;
}seqList,*pSeqList;

pSeqList initSeqList(void);							//构造一个空线性表
int lengthSeqList(pSeqList L);						//求长度
int locationSeqlist(pSeqList L,DataType X);			//检索操作
bool insertSeqList(pSeqList L,DataType X,int i);	//插入元素
int daleteSeqList(pSeqList L,int i);				//删除顺序表元素
