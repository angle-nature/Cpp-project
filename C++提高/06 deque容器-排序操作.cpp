#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>

ostream& operator<<(ostream& cout, deque<int>& d)
{
	for (deque<int>::iterator it = d.begin(); it < d.end(); it++)
	{
		cout << *it << " ";
	}
	return cout;
}

//deuqe��������
void test()
{ 
	deque<int>d1;

	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);

	cout << "����ǰ��" << endl;
	cout << d1 << endl;

	//���� Ĭ��������� �Ӵ�С ����
	//����֧��������ʵĵ�����������������������sort�㷨ֱ�Ӷ����������
	//vector����Ҳ��������sort����

	sort(d1.begin(), d1.end());
	cout << "�����" << endl;
	cout << d1 << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}