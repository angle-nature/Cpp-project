#include<stdio.h>
#include<stdlib.h>
#include"linkStack.h"

//��ʼ����ջ
pLinkStack initLinkStack()
{
	BiTree t = (BiTree)malloc(sizeof(BiTNode));
	pLinkStack head;
	head = (pLinkStack)malloc(sizeof(linkStack));

	if (head != NULL)
	{
		head->data = t;
		head->next = NULL;
	}

	return head;
}

//�ж���ջ�Ƿ�Ϊ��
bool isEmptyLinkStack(pLinkStack S)
{
	if (S->next == NULL)
		return true;
	else
		return false;
}

//��ջ
bool pushLinkStack(pLinkStack S, DataType X)
{
	pLinkStack p;
	p = (pLinkStack)malloc(sizeof(linkStack));

	if (p == NULL)       //�����ڴ�ռ�ʧ�ܣ�ջ��  ��ջʧ��
		return false;

	else
	{
		p->data = X;
		p->next = S->next;
		S->next = p;
		return true;
	}
}

//��ջ
bool popLinkStack(pLinkStack S)
{
	if (isEmptyLinkStack(S))  //ջ��  ��ջʧ��
		return false;
	else
	{
		pLinkStack p;
		p = S->next;
		S->next = p->next;
		free(p);
		return true;
	}
}

//ȡջ��Ԫ��
DataType getTopLinkStack(pLinkStack S)
{
	if (!isEmptyLinkStack(S))
		return S->next->data;
	else
	{
		printf("ջΪ�գ�");
		return 0;
	}

}

//����ջ
void destroyLinkStack(pLinkStack S)
{
	if (!isEmptyLinkStack(S))
	{
		pLinkStack p;
		while (S->next != NULL)
		{
			p = S->next;
			S->next = p->next;
			free(p);
		}
	}
	free(S);
}

////��ӡջ������Ԫ��
//void printLinkStack(pLinkStack S)
//{
//	if (!isEmptyLinkStack(S))
//	{
//		pLinkStack p;
//		p = S->next;
//		while (p != NULL)
//		{
//			printf("%d", p->data);
//			p = p->next;
//		}
//
//		putchar('\n');
//	}
//
//	else
//		printf("ջΪ�գ�");
//}