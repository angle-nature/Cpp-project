#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef struct Node
{
	int id;
	Node* Next;
}*pLinkList;

//�������� n ���˵�����
pLinkList initLink(int n)
{
	pLinkList head;

	head = (pLinkList)malloc(sizeof(Node));
	head->id = 1;
	head->Next = NULL;
	pLinkList cyclic = head;

	for (int i = 2; i <= n; i++)
	{
		pLinkList temp = (pLinkList)malloc(sizeof(Node));
		temp->id = i;
		temp->Next = NULL;
		cyclic->Next = temp;
		cyclic = cyclic->Next;
	}
	cyclic->Next = head;  //����β���� ����ѭ������

	return head;
}

//��ѭ������ĳ���
int length(const pLinkList head)
{
	int count = 0;
	pLinkList p = head;

	do
	{
		count++;
		p = p->Next;
	} while (p != head);

	return count;
}

//���Լɪ������
pLinkList solve(pLinkList head,int circleCount)
{
	pLinkList p = head;

	int count = 0;
	while (length(p) > 1)
	{
		count++;

		//ÿ��ѭ����ѭ��������ǰһ����ʱ  �����������
		if (count == circleCount - 1)
		{
			//ɾ����һ�ֵĵ� circleCount ���� ������
			pLinkList tempCell = p->Next;
			p->Next = p->Next->Next;
			printf("%d���ѳ��֣�\n",tempCell->id);
			free(tempCell);

			count = 0;  //��count�������� ��ʼ��һ��
			p = p->Next;  //�������������
		}
		else
			p = p->Next;
	}

	return p;
}

int main()
{
	printf("����ʵ�֣�\n\n");

	int number, circleCount;
	printf("������������n��ѭ������c��");
	scanf_s("%d%d", &number, &circleCount);

	printf("=================\n����˳��Ϊ��\n");
	pLinkList head = solve(initLink(number),circleCount);

	printf("=====================\n");
	printf("δ������id��%d\n", head->id);

	free(head);

	return 0;
}