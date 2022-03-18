#ifndef _List_H_
#define _List_H_

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

List MakeEmpty();									//创建空链表
bool IsEmpty(List L);								//判断链表是否为空
bool IsLast(Position p, List L);					//判断是否是最后一个元素
Position Find(ElementType X, List L);				//查找元素
void Delete(ElementType X, List L);					//删除指定值的元素
Position FindPrevious(ElementType X, List L);		//找到元素的前一个的位置
void Insert(ElementType X, List L,Position p);		//插入元素
void DeleteList(List L);							//删除链表
Position Header(List L);							//求链表头部
Position First(List L);								//求链表尾部
ElementType Retrieve(Position p);					//返回节点的值

//创建链表结构体
struct Node
{
	ElementType Element;
	Position Next;  //Next 用于指向下一个链表结构体的地址
};

#endif  _List_H_

