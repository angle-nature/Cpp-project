#include<iostream>
using namespace std;

//string �ַ���ȡ

void test()
{
	string str1 = "hello";

	//1��ͨ��[]���ʵ����ַ�
	for (int i = 0; i < str1.size(); i++)
	{
		cout << str1[i] << " ";
	}
	cout << endl;

	//ͨ��at��ʽ���ʵ����ַ�
	for (int i = 0; i < str1.size(); i++)
	{
		cout << str1.at(i) << " ";
	}
	cout << endl;

	//�޸ĵ����ַ�
	str1[0] = 'x';
	cout << "str1=" << str1 << endl;

	str1.at(1) = 'd';
	cout << "str1=" << str1 << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}