#pragma once

#define MAXSIZE 100

typedef int DataType;

typedef struct 
{
	DataType data[MAXSIZE];
	int length;
}seqList,*pSeqList;

pSeqList initSeqList(void);							//����һ�������Ա�
int lengthSeqList(pSeqList L);						//�󳤶�
int locationSeqlist(pSeqList L,DataType X);			//��������
bool insertSeqList(pSeqList L,DataType X,int i);	//����Ԫ��
int daleteSeqList(pSeqList L,int i);				//ɾ��˳���Ԫ��
