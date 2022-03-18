#pragma once

#define MAXSIZE 100

typedef struct
{
	int x, y, d;
}DataType;

typedef struct
{
	DataType data[MAXSIZE];
	int top;
}seqStack, * pSeqStack;

pSeqStack initSeqStack(void);                //��ʼ��˳��ջ
bool isEmptySeqStack(pSeqStack S);           //�ж�ջ�Ƿ�Ϊ��
bool pushSeqStack(pSeqStack S, DataType X);  //��ջ
DataType popSeqStack(pSeqStack S);           //��ջ
DataType getTopSeqStack(pSeqStack S);        //ȡջ��Ԫ��
void destroySeqStack(pSeqStack* S);          //����ջ