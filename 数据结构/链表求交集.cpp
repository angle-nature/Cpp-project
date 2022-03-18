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

//����������
List creatList()
{
	List Head;
	Head = (List)malloc(sizeof(Node));
	if (Head != NULL)   /*ȷ�ϴ���ͷ��㴴���Ƿ�ɹ������ɹ����޸ĵ�����ͷ����ָ����Ϊ0��ձ�*/
		Head->Next = NULL;
	return Head;
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


//������Ԫ�صĽ���  ��A��B����Ϊ���������
List LinkListMixed(const List A, const List B)
{
	List head = creatList(); //��һ���µ����������潻��
	ptrToNode p = head, pa = A->Next, pb = B->Next;

	while (pa != NULL && pb != NULL)
	{
		if (pa->X < pb->X)
			pa = pa->Next;
		else if (pa->X > pb->X)
			pb = pb->Next;
		else if (pa->X == pb->X)  //��A��B�е�Ԫ�����ʱ ���浽��������
		{
			Insert(pa->X, head, p);  //����Ԫ��
			pa = pa->Next;
			pb = pb->Next;
			p = p->Next;
		}
	}
	return head;
}

int main()
{

	List A = creatList();
	List B = creatList();

	ptrToNode pa = A, pb = B;

	//���β���  1��10  ʮ����
	for (int i = 1; i <= 10; i++)
	{
		Insert(i, A, pa);
		pa = pa->Next;
	}
	//���β���  3��12  ʮ����
	for (int i = 3; i <= 12; i++)
	{
		Insert(i, B, pb);
		pb = pb->Next;
	}

	List p = LinkListMixed(A, B);

	printf("����A��Ԫ�أ�\n");
	printList(A);
	printf("����B��Ԫ�أ�\n");
	printList(B);
	printf("������Ԫ�أ�\n");
	printList(p);

	return 0;
}
