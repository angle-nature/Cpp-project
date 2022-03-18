#include<iostream>
using namespace std;

#define NUMBER 41
typedef struct Node* person;

struct Node
{
	int id;
	person Next;
};

//��������41���˵�����
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
	cyclic->Next = head;  //����β���� ����ѭ������

	return head;
}

//��ѭ������ĳ���
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

//���ĺ���
person solve(person head)
{
	person p = head;

	int count = 0;
	int i = 0;

	while (length(p) >= 3)
	{
		count++;
	
		//ÿ��ѭ����ÿһ�ֵĵڶ�����ʱ ����if���
		if (count == 2)
		{
			i++;

			//ɾ����һ�ֵĵ������� ������
			person tempCell = p->Next;
			p->Next = p->Next->Next;
			cout << tempCell->id << "���ѳ���!\t";
			delete tempCell;

			count = 0;  //��count�������� ��ʼ��һ��
			p = p->Next;  //�������������

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
		cout << p->id <<"��δ����"<< endl;
		p = p->Next;
	} while (p != head);

	system("pause");
	return 0;
}