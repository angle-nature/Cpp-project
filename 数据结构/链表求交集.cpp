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

//创建空链表
List creatList()
{
	List Head;
	Head = (List)malloc(sizeof(Node));
	if (Head != NULL)   /*确认创建头结点创建是否成功，若成功，修改单链表头结点的指针域为0表空表*/
		Head->Next = NULL;
	return Head;
}

//在指定位置插入元素
void Insert(ElementType x, List H, Position p)
{
	Position TmpCell;

	TmpCell = (Position)malloc(sizeof(struct Node));

	//若未申请成功 输出错误 并退出程序
	if (TmpCell == NULL)
	{
		printf("out of space!!!");
		exit(-1); //非正常退出
	}

	//若插入的位置为空  则也需开辟一个新的内存空间
	if (p == NULL)
	{
		p = (Position)malloc(sizeof(struct Node));
		p->Next = NULL;
	}


	TmpCell->X = x;
	TmpCell->Next = p->Next;
	p->Next = TmpCell;

}

//求链表长度
int lengthOfList(List H)
{
	ptrToNode p = H->Next; //链表带头结点 头节点不算长度 故指向头节点的下一个节点
	int count = 0;

	while (p != NULL)
	{
		count++;
		p = p->Next;
	}

	return count;
}

//输出链表的所有元素
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
		printf("该链表为空！");
	putchar('\n');
}


//求链表元素的交集  且A与B链表为递增有序的
List LinkListMixed(const List A, const List B)
{
	List head = creatList(); //用一个新的链表来储存交集
	ptrToNode p = head, pa = A->Next, pb = B->Next;

	while (pa != NULL && pb != NULL)
	{
		if (pa->X < pb->X)
			pa = pa->Next;
		else if (pa->X > pb->X)
			pb = pb->Next;
		else if (pa->X == pb->X)  //当A与B中的元素相等时 储存到新链表中
		{
			Insert(pa->X, head, p);  //插入元素
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

	//依次插入  1到10  十个数
	for (int i = 1; i <= 10; i++)
	{
		Insert(i, A, pa);
		pa = pa->Next;
	}
	//依次插入  3到12  十个数
	for (int i = 3; i <= 12; i++)
	{
		Insert(i, B, pb);
		pb = pb->Next;
	}

	List p = LinkListMixed(A, B);

	printf("链表A的元素：\n");
	printList(A);
	printf("链表B的元素：\n");
	printList(B);
	printf("交集的元素：\n");
	printList(p);

	return 0;
}
