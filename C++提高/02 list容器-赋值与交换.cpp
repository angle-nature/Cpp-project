#include<iostream>
using namespace std;
#include<list>

ostream& operator<<(ostream& cout, list<int>& L)
{
	for (list<int>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	return cout;
}

//list��ֵ
void test()
{
	list<int>L1; //Ĭ�Ϲ��� �޲ι���

	for (int i = 0; i < 10; i++)
	{
		L1.push_back(i);
	}
	cout << L1 << endl;

	//operator= ��ֵ
	list<int> L2 = L1;
	cout << L2 << endl;

	//assign
	list<int> L3;
	L3.assign(L1.begin(), L1.end()); //list�ĵ�����ֻ�ܽ��� ++ �� --�Ĳ���
	cout << L3 << endl;

	//n��elem��ʽ��ֵ
	list<int> L4;
	L4.assign(10, 100);
	cout << L4 << endl;

	//��������
	L1.swap(L4);
	cout << "������" << endl;
	cout << "L1=" << L1 << endl;
	cout << "L4=" << L4 << endl;
}



int main()
{
	test();

	system("pause");

	return 0;
}