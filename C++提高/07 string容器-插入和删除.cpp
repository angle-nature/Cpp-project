#include<iostream>
using namespace std;

//string �ַ��������ɾ��

void test()
{
	string str = "hello";

	//����
	str.insert(1, "123");   //���±�Ϊ 1 ��λ�ò����ַ���"123"
	cout << "str=" << str << endl;

	//ɾ��
	str.erase(1, 3);  //���±�Ϊ 1 ��λ�ÿ�ʼɾ�� 3 ���ַ�
	cout << "str=" << str << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}