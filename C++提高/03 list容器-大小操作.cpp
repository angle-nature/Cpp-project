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

//vector�����������ʹ�С����
void test()
{
	list<int>L1;

	for (int i = 0; i < 10; i++)
	{
		L1.push_back(i);
	}
	cout << L1 << endl;

	if (L1.empty())
	{
		cout << "v1Ϊ��" << endl;
	}
	else
	{
		cout << "v1��Ϊ��" << endl;
		cout << "v1�Ĵ�СΪ��" << L1.size() << endl;
	}

	//����ָ����С
	L1.resize(15);
	//v1.resize(15,100); //Ҳ��������resize���ذ汾��ָ�����ֵ����2��100��
	cout << L1 << endl; //�������ָ���ı�ԭ���ĳ��ˣ�Ĭ����0����µ�λ��

	L1.resize(5);
	cout << L1 << endl; //�������ָ���ı�ԭ���Ķ��ˣ����������Զ�ɾ��
}

int main()
{
	test();

	system("pause");

	return 0;
}