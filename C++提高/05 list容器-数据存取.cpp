#include<iostream>
using namespace std;
#include<list>

//vector���������ݴ�ȡ����
void test()
{
	list<int>L1;

	//β��
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);

	//L[0]; ��������[]����list�����е�Ԫ��
	//L1.at(0);  ��������at��ʽ����list�����е�Ԫ��
	//ԭ����list����������������һ�������Կռ�洢����

	cout << "��һ��Ԫ��Ϊ��" << L1.front() << endl;
	cout << "���һ��Ԫ��Ϊ��" << L1.back() << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}