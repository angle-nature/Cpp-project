#include<iostream>
using namespace std;

#define NUMBER 41
typedef struct Node* person;

struct Node
{
	int id;
	person Next;
};

//创建包含41个人的链表
person initLink()
{
	person head;
	
	head = (person)new Node;
	head->id = 1;
	head->Next = NULL;
	person cyclic = head;

	for (int i = 2; i <= NUMBER; i++)
	{
		person temp = (person)new Node;
		temp->id = i;
		temp->Next = NULL;
		cyclic->Next = temp;
		cyclic = cyclic->Next;
	}
	cyclic->Next = head;  //将首尾连接 构成循环链表

	return head;
}

//求循环链表的长度
int length(const person head)
{
	int count = 0;
	person p = head;

	do
	{
		count++;
		p = p->Next;
	} while (p != head);

	return count;
}

//核心函数
person solve(person head)
{
	person p = head;

	int count = 0;
	int i = 0;

	while (length(p) >= 3)
	{
		count++;
	
		//每当循环到每一轮的第二个人时 进入if语句
		if (count == 2)
		{
			i++;

			//删除这一轮的第三个人 即出局
			person tempCell = p->Next;
			p->Next = p->Next->Next;
			cout << tempCell->id << "号已出局!\t";
			delete tempCell;

			count = 0;  //将count重新置零 开始下一轮
			p = p->Next;  //链表继续往下走

			if (i % 5 == 0)
				cout << endl;
		}
		else
			p = p->Next;
	}
		
	return p;
}

int main()
{
	person head = solve(initLink());

	person p = head;

	cout << endl;
	cout << "=========================================" << endl;

	do
	{
		cout << p->id <<"号未出局"<< endl;
		p = p->Next;
	} while (p != head);

	system("pause");
	return 0;
}