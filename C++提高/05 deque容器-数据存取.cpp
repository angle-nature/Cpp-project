#include<iostream>
using namespace std;
#include<deque>

//deque���������ݴ�ȡ����
void test()
{
	deque<int>d1;

	//β��
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}

	//����[]�ķ�ʽ���ʵ���Ԫ��
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1[i] << " ";
	}
	cout << endl;

	//����at��ʽ���ʵ���Ԫ��
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1.at(i) << " ";
	}
	cout << endl;

	//��ȡ��2��Ԫ��
	cout << "��һ��Ԫ�أ�" << d1.front() + 1 << endl;

	//��ȡ���һ��Ԫ��
	cout << "���һ��Ԫ�أ�" << d1.back() << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}