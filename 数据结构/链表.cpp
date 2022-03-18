#include<stdio.h>
#include<stdlib.h>

typedef  int ElementType;
typedef struct Node* ptrToNode;
typedef ptrToNode List;
typedef ptrToNode Position;

struct Node
{
	ElementType X;
	ptrToNode Next;
};

Position FindPrevious(ElementType x, List L);

//����������
List creatList()
{
	List Head;
	Head = (List)malloc(sizeof(Node));
	if (Head!=NULL)   /*ȷ�ϴ���ͷ��㴴���Ƿ�ɹ������ɹ����޸ĵ�����ͷ����ָ����Ϊ0��ձ�*/
		Head->Next = NULL;
	return Head;
}

//��������
void destroyList(List *H)
{
	ptrToNode p = *H;
	ptrToNode tempCell;

	while (p != NULL)
	{
		tempCell = p;
		p = p->Next;
		free(tempCell);
	}

	*H = NULL;
}

//��������
int lengthOfList(List H)
{
	ptrToNode p = H->Next; //�����ͷ��� ͷ�ڵ㲻�㳤�� ��ָ��ͷ�ڵ����һ���ڵ�
	int count = 0; 

	while (p != NULL)
	{
		count++;
		p = p->Next;
	}

	return count;
}

//��ֵ����
Position locationList(List H,ElementType x)
{
	ptrToNode p = H;

	while (p != NULL)
	{
		if (p->X = x)
			return p;
		else
			p = p->Next;
	}

	return NULL;  //��û���ҵ��򷵻ؿ�ָ��
}

//��ָ��λ�ò���Ԫ��
void Insert(ElementType x, List H, Position p)
{
	Position TmpCell;

	TmpCell = (Position)malloc(sizeof(struct Node));

	//��δ����ɹ� ������� ���˳�����
	if (TmpCell == NULL)
	{
		printf("out of space!!!");
		exit(-1); //�������˳�
	}

	//�������λ��Ϊ��  ��Ҳ�迪��һ���µ��ڴ�ռ�
	if (p == NULL)
	{
		p = (Position)malloc(sizeof(struct Node));
		p->Next = NULL;
	}


	TmpCell->X = x;
	TmpCell->Next = p->Next;
	p->Next = TmpCell;

}

//ɾ��ָ��Ԫ�����ڵĽڵ�
void Delete(ElementType x, List H)
{
	Position p, TmpCell;

	p = FindPrevious(x, H); //�ҵ�ָ��Ԫ��ǰһ��λ�� �������ַ

	TmpCell = p->Next;
	p->Next = p->Next->Next;
	free(TmpCell);
}

//�ҵ�ָ��Ԫ��ǰһ��λ�� �������ַ
Position FindPrevious(ElementType x, List L)
{
	Position p;

	p = L->Next;
	while (p != NULL && p->Next->X != x)
		p = p->Next;

	return p;
}

//������������Ԫ��
void printList(List H)
{
	ptrToNode p = H;

	if (p != NULL)
		for (int i = 0; i < lengthOfList(H); i++)
		{
			p = p->Next;
			printf("%d ", p->X);
		}
	else
		printf("������Ϊ�գ�");
	putchar('\n');
}

int main()
{
	List head = creatList();  //����������
	ptrToNode p = head;

	//���β���  1��10  ʮ����
	for (int i = 1; i <= 10; i++)
	{
		Insert(i, head, p);
		p = p->Next;
	}
	printList(head); //�������

	printf("====================\n");
	Delete(4,head);  //ɾ�������е�Ԫ�� 4
	printList(head); //�������

	printf("====================\n");
	printf("%d\n", locationList(head, 6)->X);  //���ָ��Ԫ�ص�λ�õ�Ԫ��

	printf("====================\n");
	printf("������Ϊ��%d\n", lengthOfList(head));  //���������

	printf("====================\n");
	destroyList(&head);  //��������
	printList(head);

	return 0;
}