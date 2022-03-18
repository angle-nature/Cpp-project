#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef struct node
{
	int arr[MAXSIZE];
	int length;
}seqList,*pSeqList;

//�������� n ������˳���
pSeqList creatSeqList(int n)
{
	pSeqList p = (pSeqList)malloc(sizeof(node));
	p->length = n;
	
	//�� arr[0] ��ʼ�� 1
	for (int i = 0; i < n; i++)
	{
		p->arr[i] = i+1;
	}

	return p;
}

//ɾ��ָ���±�����Ԫ��
void deleteSeqList(pSeqList p,int index)
{
	for (int i = index; i < p->length-1; i++)
	{
		p->arr[i] = p->arr[i + 1];
	}

	p->length--;
}

//���Լɪ������
pSeqList josephus_SeqList(pSeqList p, int circleCount)
{
	int count = 0;
	int i = 0;
	while (p->length > 1)
	{
		i = (i + 1) % p->length;  //�����±�  �����鳤��ȡģ����ѭ��
		count++;  //ѭ������
		if (count == circleCount-1 )  //ÿ��ѭ����ѭ��������ǰһ����ʱ  �����������
		{
			printf("%d���ѳ���\n", p->arr[i]);  //��Ϊ�����±��0��ʼ  ��ɾ���±�i��Ӧ������Ԫ��
			deleteSeqList(p, i);  //ɾ��Ԫ��
			count = 0;  //ɾ����count����  ��ʼ��һ��ѭ��
		}

	}

	return p;
}

int main()
{
	printf("˳���ʵ�֣�\n\n");

	int number, circleCount;
	printf("������������n��ѭ������c��");
	scanf_s("%d%d", &number, &circleCount);

	printf("=================\n����˳��Ϊ��\n");
	pSeqList p=josephus_SeqList(creatSeqList(number), circleCount);

	printf("=====================\n");
	printf("δ������id��%d\n",p->arr[0]);

	free(p);

	return 0;
}