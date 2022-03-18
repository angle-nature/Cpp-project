#pragma once
#include"TempBiTree.h"

typedef int DataType;

struct Stack
{
	DataType data;
	Stack* next;
};

typedef Stack linkStack;
typedef Stack* pLinkStack;

pLinkStack initLinkStack(void);                    //��ʼ��ջ
bool isEmptyLinkStack(pLinkStack S);               //�ж�ջ�Ƿ�Ϊ��
bool pushLinkStack(pLinkStack S, DataType X);      //��ջ
bool popLinkStack(pLinkStack S);                   //��ջ
DataType getTopLinkStack(pLinkStack S);            //ȡջ��Ԫ��
void destroyLinkStack(pLinkStack S);               //����ջ
void printLinkStack(pLinkStack S);                 //��ӡջ�е�����Ԫ��