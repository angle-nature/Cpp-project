#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef struct Node
{
	int id;
	Node* Next;
}*pLinkList;

//创建包含 n 个人的链表
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
	cyclic->Next = head;  //将首尾连接 构成循环链表

	return head;
}

//求循环链表的长度
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

//解决约瑟夫问题
pLinkList solve(pLinkList head,int circleCount)
{
	pLinkList p = head;

	int count = 0;
	while (length(p) > 1)
	{
		count++;

		//每当循环到循环次数的前一个人时  进入条件语句
		if (count == circleCount - 1)
		{
			//删除这一轮的第 circleCount 个人 即出局
			pLinkList tempCell = p->Next;
			p->Next = p->Next->Next;
			printf("%d号已出局！\n",tempCell->id);
			free(tempCell);

			count = 0;  //将count重新置零 开始下一轮
			p = p->Next;  //链表继续往下走
		}
		else
			p = p->Next;
	}

	return p;
}

int main()
{
	printf("链表实现：\n\n");

	int number, circleCount;
	printf("请输入总人数n和循环次数c：");
	scanf_s("%d%d", &number, &circleCount);

	printf("=================\n出局顺序为：\n");
	pLinkList head = solve(initLink(number),circleCount);

	printf("=====================\n");
	printf("未出局人id：%d\n", head->id);

	free(head);

	return 0;
}