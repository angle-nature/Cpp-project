#include<iostream>
using namespace std;
#include<vector>
#include<algorithm> //��׼�㷨��ͷ�ļ�

void func(int a)
{
	cout << a << endl;
}

//vector���������������

void test()
{
	//������һ��vector����������
	vector<int> v;

	//�������в�������
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//��һ�ֱ�����ʽ
	//ͨ�����������������е�����
	//vector<int>::iterator itBegin = v.begin(); //��ʼ��������ָ�������еĵ�һ��Ԫ��
	//vector<int>::iterator itEnd = v.end(); //������������ָ�����������һ��Ԫ�ص���һ��λ��

	//while (itBegin != itEnd)
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}

	//�ڶ��ֱ�����ʽ
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << *it << endl;
	//}

	//�����ַ�ʽ������STL�ṩ�����㷨
	for_each(v.begin(), v.end(), func);
}

int main()
{
	test();

	system("pause");

	return 0;
}