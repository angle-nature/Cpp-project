#ifndef _List_H_
#define _List_H_

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

List MakeEmpty();									//����������
bool IsEmpty(List L);								//�ж������Ƿ�Ϊ��
bool IsLast(Position p, List L);					//�ж��Ƿ������һ��Ԫ��
Position Find(ElementType X, List L);				//����Ԫ��
void Delete(ElementType X, List L);					//ɾ��ָ��ֵ��Ԫ��
Position FindPrevious(ElementType X, List L);		//�ҵ�Ԫ�ص�ǰһ����λ��
void Insert(ElementType X, List L,Position p);		//����Ԫ��
void DeleteList(List L);							//ɾ������
Position Header(List L);							//������ͷ��
Position First(List L);								//������β��
ElementType Retrieve(Position p);					//���ؽڵ��ֵ

//��������ṹ��
struct Node
{
	ElementType Element;
	Position Next;  //Next ����ָ����һ������ṹ��ĵ�ַ
};

#endif  _List_H_

