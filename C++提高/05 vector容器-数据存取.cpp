#include<iostream>
using namespace std;
#include<vector>

//vector���������ݴ�ȡ����
void test()
{
	vector<int>v1;

	//β��
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	//����[]�ķ�ʽ���ʵ���Ԫ��
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	//����at��ʽ���ʵ���Ԫ��
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;

	//��ȡ��2��Ԫ��
	cout << "��һ��Ԫ�أ�" << v1.front()+1 << endl;

	//��ȡ���һ��Ԫ��
	cout << "���һ��Ԫ�أ�" << v1.back() << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}