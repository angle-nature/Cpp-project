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

//创建空链表
List creatList()
{
	List Head;
	Head = (List)malloc(sizeof(Node));
	if (Head!=NULL)   /*确认创建头结点创建是否成功，若成功，修改单链表头结点的指针域为0表空表*/
		Head->Next = NULL;
	return Head;
}

//销毁链表
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

//按值检索
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

	return NULL;  //若没有找到则返回空指针
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

//删除指定元素所在的节点
void Delete(ElementType x, List H)
{
	Position p, TmpCell;

	p = FindPrevious(x, H); //找到指定元素前一个位置 返回其地址

	TmpCell = p->Next;
	p->Next = p->Next->Next;
	free(TmpCell);
}

//找到指定元素前一个位置 返回其地址
Position FindPrevious(ElementType x, List L)
{
	Position p;

	p = L->Next;
	while (p != NULL && p->Next->X != x)
		p = p->Next;

	return p;
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

int main()
{
	List head = creatList();  //创建空链表
	ptrToNode p = head;

	//依次插入  1到10  十个数
	for (int i = 1; i <= 10; i++)
	{
		Insert(i, head, p);
		p = p->Next;
	}
	printList(head); //输出链表

	printf("====================\n");
	Delete(4,head);  //删除链表中的元素 4
	printList(head); //输出链表

	printf("====================\n");
	printf("%d\n", locationList(head, 6)->X);  //输出指定元素的位置的元素

	printf("====================\n");
	printf("链表长度为：%d\n", lengthOfList(head));  //输出链表长度

	printf("====================\n");
	destroyList(&head);  //销毁链表
	printList(head);

	return 0;
}