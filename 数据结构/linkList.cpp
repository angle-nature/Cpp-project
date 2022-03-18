#include<stdio.h>
#include"linkList.h"
#include<stdlib.h>

//����������
List MakeEmpty()
{
	List L;
	L = (List)malloc(sizeof(Node));

	if (L == NULL)
		printf("out of space��");
	else
	{
		L->Element = 0;
		L->Next = NULL;
	}

	return L;

}

//�ж������Ƿ�Ϊ��
bool IsEmpty(List L)
{
	return L->Next == NULL;
}

//�ж�p�ڵ��Ƿ������һ��
bool IsLast(Position p, List L)
{
	return p->Next == NULL;
}

//�ҵ�ָ��Ԫ�����ڵ�λ�� �������ַ
Position Find(ElementType X, List L)
{
	Position p;

	p = L->Next;
	while (p != NULL && p->Element != X)
		p = p->Next;

	return p;
}

//�ҵ�ָ��Ԫ��ǰһ��λ�� �������ַ
Position FindPrevious(ElementType X, List L)
{
	Position p;

	p = L->Next;
	while (p != NULL && p->Next->Element != X)
		p = p->Next;

	return p;
}

//ɾ��ָ��Ԫ�����ڵĽڵ�
void Delete(ElementType X, List L)
{
	Position p, TmpCell;

	p = FindPrevious( X, L);

	TmpCell = p->Next;
	p->Next = p->Next->Next;
	free(TmpCell);
}

//��ָ��λ�ò�������
void Insert(ElementType X, List L, Position p)
{
	Position TmpCell;

	//���� Node ��С���ڴ�ռ�  malloc��������ֵ�� void* ����  ��ǿ��ת���� Position ����
	TmpCell = (Position)malloc(sizeof(struct Node));

	//��δ����ɹ� ������� ���˳�����
	if (TmpCell == NULL)
	{
		printf("out of space!!!");
		exit(-1); //�������˳�
	}

	TmpCell->Element = X;
	TmpCell->Next = p->Next;
	p->Next = TmpCell;

}

//ɾ����������
void DeleteList(List L)
{
	Position p, TmpCell;

	p = L->Next;    //ʹpָ������ĵڶ����ڵ�
	L->Next = NULL;  //ʹ��һ���ڵ��ָ���ÿ�
	while (p!=NULL)
	{
		TmpCell = p->Next; //����ʱ��������p����һ���ڵ��ַ
		free(p);  //�ͷ�p�ڵ�
		p = TmpCell;  //����p�ڵ�
	}
}

//���ر�ͷ
Position Header(List L)
{
	return L;
}

//���ص�һ���ڵ�
Position First(List L)
{
	return L->Next;
}

//���ظýڵ��ֵ
ElementType Retrieve(Position p)
{
	return p->Element;
}
