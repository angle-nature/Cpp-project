#include<iostream>
using namespace std;
#include<list>

//���
void printlist(list<int>& l)
{
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//list��������
void test()
{
	//����list����
	list<int>l1; //Ĭ�Ϲ��� �޲ι���

	for (int i = 0; i < 10; i++)
	{
		l1.push_back(i);
	}

	//��������
	printlist(l1);

	//ͨ�����䷽ʽ���й���
	list<int> l2(l1.begin(), l1.end());

	printlist(l2);

	//n��elem��ʽ����
	list<int> l3(10, 17);  //���� 10 �� 17 
	printlist(l3);

	//��������
	list<int> l4(l3);
	printlist(l4);
}

int main()
{
	test();

	system("pause");

	return 0;
}