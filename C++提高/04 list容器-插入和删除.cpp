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

//vector�����Ĳ����ɾ������
void test()
{
	list<int>L1;

	//β��
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);

	//ͷ��
	L1.push_front(100);
	L1.push_front(200);
	L1.push_front(300);

	cout << L1 << endl;

	//βɾ
	L1.pop_back();  //ɾ�����һ��Ԫ��
	cout << L1 << endl;

	//ͷɾ
	L1.pop_front();
	cout << L1 << endl;

	//���� ��һ�������ǵ�����
	L1.insert(L1.begin(), 100);
	cout << L1 << endl;

	L1.insert(L1.begin(), 2, 317);
	cout << L1 << endl;

	//ɾ�� ����Ҳ�ǵ�����
	L1.erase(L1.begin());
	cout << L1 << endl;

	L1.push_back(10000);
	L1.push_back(10000);
	L1.push_back(10000);
	cout << L1 << endl;

	L1.remove(10000); //�Ƴ���������Ϊ10000��Ԫ��
	cout << L1 << endl;

	//����ɾ��
	L1.erase(L1.begin(), L1.end());
	cout << L1 << endl;

	//���
	L1.clear();
	cout << L1 << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}