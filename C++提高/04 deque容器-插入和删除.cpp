#include<iostream>
using namespace std;
#include<deque>

ostream& operator<<(ostream& cout, deque<int>& d)
{
	for (deque<int>::iterator it = d.begin(); it < d.end(); it++)
	{
		cout << *it << " ";
	}
	return cout;
}

//deque�����Ĳ����ɾ������

//���˲���
void test()
{
	deque<int>d1;

	//β��
    d1.push_back(10);
	d1.push_back(20);

	//ͷ��
	d1.push_front(100);
	d1.push_front(200);

	cout << d1 << endl;

	//βɾ
	d1.pop_back();  //ɾ�����һ��Ԫ��
	cout << d1 << endl;

	//ͷɾ
	d1.pop_front();
	cout << d1 << endl;

	//���� ��һ�������ǵ�����
	d1.insert(d1.begin() + 2, 100);
	cout << d1 << endl;

	d1.insert(d1.begin(), 2, 317);
	cout << d1 << endl;

	//���������
	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);

	d1.insert(d1.begin(), d2.begin(), d2.end());
	cout << d1 << endl;

	//ɾ�� ����Ҳ�ǵ�����
	d1.erase(d1.begin() + 3);
	cout << d1 << endl;

	//����ɾ��
	d1.erase(d1.begin() + 4, d1.end() - 1);
	cout << d1 << endl;

	//���
	d1.clear();
	cout << d1 << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}