#include<iostream>
using namespace std;
#include<list>
#include<algorithm>

ostream& operator<<(ostream& cout, list<int>& L)
{
	for (list<int>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	return cout;
}

//bool comparePeson(Person& p1, Person& p2)
//{
//	//����������
//	if (p1.m_Age == p2.m_Age)
//	{
//		//������ͬ ����߽���
//		return p1.m_H > p1.p2m_H;
//	}
//	else
//	{
//		return p1.m_Age < p2.m_Age;
//	}
//}

bool myCompare(int val1, int val2)
{
	//���� ���õ�һ�������ڵڶ�����
	return val1 > val2;
}

//vector�����Ĳ����ɾ������
void test()
{
	list<int>L1;

	//β��
	L1.push_back(20);
	L1.push_back(10);
	L1.push_back(30);
	L1.push_back(50);
	L1.push_back(40);

	cout << "��תǰ��" << endl;
	cout << L1 << endl;

	L1.reverse();
	cout << "��ת��" << endl;
	cout << L1 << endl;

	//���в�֧��������ʵ��������������������ñ�׼�㷨
	//��֧��������ʵ��������������ڲ����ṩһЩ�㷨
	
	//sort(L1.begin(), L1.end());  //����

	L1.sort();
	cout << "�����" << endl; //Ĭ�Ϲ��� ��С���� ����
	cout << L1 << endl;

	L1.sort(myCompare); //����
	cout << L1 << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}