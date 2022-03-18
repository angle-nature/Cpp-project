#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXLEN 100
#define NLAYER  4

typedef struct BiTNode               // ����������ڵ�ṹ
{
	char data;                       // ������
	struct BiTNode* LChild, * RChild;  // ���Һ���ָ����
}BiTNode, * BiTree;
BiTree T;

//����������
void CreateBiTree(BiTree* bt)
{ // �����������н����������Ķ�������Ĺ���
	char ch;
	scanf_s("%c", &ch);
	if (ch == '#')
		*bt = NULL;
	else
	{
		*bt = (BiTree)malloc(sizeof(BiTNode)); // ����һ���½��
		(*bt)->data = ch;
		CreateBiTree(&((*bt)->LChild));      // ����������
		CreateBiTree(&((*bt)->RChild));      // ����������
	}
}

//���ʹ�ӡ������
void TranslevelPrint(BiTree bt)
{  //���㷨ʵ�ֶ������İ����ӡ
	struct node
	{
		BiTree vec[MAXLEN];           // ����������
		int layer[MAXLEN];            // ������ڵĲ�
		int locate[MAXLEN];           // ��ӡ����λ��
		int front, rear;
	}q;                               // �������q
	int i, j, k;
	int nLocate;
	j = 1;
	k = 0;
	q.front = 0;                      // ��ʼ������q��ͷ����β
	q.rear = 0;
	printf(" ");
	q.vec[q.rear] = bt;               // �����������ڵ������
	q.layer[q.rear] = 1;
	q.locate[q.rear] = 20;
	q.rear = q.rear + 1;
	while (q.front < q.rear)
	{
		bt = q.vec[q.front];
		i = q.layer[q.front];
		nLocate = q.locate[q.front];
		if (j < i)                      // �����ӡʱ����
		{
			printf("\n");
			printf("\n");
			j = j + 1;
			k = 0;
			while (k < nLocate)
			{
				printf(" ");
				k++;
			}
		}
		while (k < (nLocate - 1))          // ���ý����ȿ��ƺ���λ��
		{
			printf(" ");
			k++;
		}
		printf("%c", bt->data);
		q.front = q.front + 1;
		if (bt->LChild != NULL)          // �����������������������ڵ������
		{
			q.vec[q.rear] = bt->LChild;
			q.layer[q.rear] = i + 1;
			q.locate[q.rear] = (int)(nLocate - pow(2, NLAYER - i - 1));
			q.rear = q.rear + 1;
		}
		if (bt->RChild != NULL)         // �����������������������ڵ������
		{
			q.vec[q.rear] = bt->RChild;
			q.layer[q.rear] = i + 1;
			q.locate[q.rear] = (int)(nLocate + pow(2, NLAYER - i - 1));
			q.rear = q.rear + 1;
		}
	}
}

//������
void Visit(char ch)
{
	printf("%c  ", ch);
}

//�������������
void  PreOrder(BiTree root)
{// �������������, rootΪָ�������(��ĳһ����)������ָ��
	if (root != NULL)
	{
		Visit(root->data);       // ���ʸ����
		PreOrder(root->LChild);  // �������������
		PreOrder(root->RChild);  // �������������
	}
}

//�������������
void  InOrder(BiTree root)
{// �������������, rootΪָ�������(��ĳһ����)������ָ��
	if (root != NULL)
	{
		InOrder(root->LChild);    // �������������
		Visit(root->data);        // ���ʸ����
		InOrder(root->RChild);    // �������������
	}
}

//�������������
void  PostOrder(BiTree root)
{//���������������rootΪָ�������(��ĳһ����)������ָ��
	if (root != NULL)
	{
		PostOrder(root->LChild);  // �������������
		PostOrder(root->RChild);  // �������������
		Visit(root->data);        // ���ʸ����
	}
}
int main()
{
	printf("����������������Ľ�����У�\n");
	CreateBiTree(&T);
	printf("���νṹΪ��\n");
	TranslevelPrint(T);
	printf("\n���������");
	PreOrder(T);
	printf("\n���������");
	InOrder(T);
	printf("\n���������");
	PostOrder(T);
	return 0;
}
