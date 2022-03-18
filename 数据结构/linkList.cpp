#include<stdio.h>
#include"linkList.h"
#include<stdlib.h>

//创建空链表
List MakeEmpty()
{
	List L;
	L = (List)malloc(sizeof(Node));

	if (L == NULL)
		printf("out of space！");
	else
	{
		L->Element = 0;
		L->Next = NULL;
	}

	return L;

}

//判断链表是否为空
bool IsEmpty(List L)
{
	return L->Next == NULL;
}

//判断p节点是否是最后一个
bool IsLast(Position p, List L)
{
	return p->Next == NULL;
}

//找到指定元素所在的位置 返回其地址
Position Find(ElementType X, List L)
{
	Position p;

	p = L->Next;
	while (p != NULL && p->Element != X)
		p = p->Next;

	return p;
}

//找到指定元素前一个位置 返回其地址
Position FindPrevious(ElementType X, List L)
{
	Position p;

	p = L->Next;
	while (p != NULL && p->Next->Element != X)
		p = p->Next;

	return p;
}

//删除指定元素所在的节点
void Delete(ElementType X, List L)
{
	Position p, TmpCell;

	p = FindPrevious( X, L);

	TmpCell = p->Next;
	p->Next = p->Next->Next;
	free(TmpCell);
}

//在指定位置插入链表
void Insert(ElementType X, List L, Position p)
{
	Position TmpCell;

	//申请 Node 大小的内存空间  malloc函数返回值是 void* 类型  需强制转换成 Position 类型
	TmpCell = (Position)malloc(sizeof(struct Node));

	//若未申请成功 输出错误 并退出程序
	if (TmpCell == NULL)
	{
		printf("out of space!!!");
		exit(-1); //非正常退出
	}

	TmpCell->Element = X;
	TmpCell->Next = p->Next;
	p->Next = TmpCell;

}

//删除整个链表
void DeleteList(List L)
{
	Position p, TmpCell;

	p = L->Next;    //使p指向链表的第二个节点
	L->Next = NULL;  //使第一个节点的指向置空
	while (p!=NULL)
	{
		TmpCell = p->Next; //用临时变量储存p的下一个节点地址
		free(p);  //释放p节点
		p = TmpCell;  //更新p节点
	}
}

//返回表头
Position Header(List L)
{
	return L;
}

//返回第一个节点
Position First(List L)
{
	return L->Next;
}

//返回该节点的值
ElementType Retrieve(Position p)
{
	return p->Element;
}
