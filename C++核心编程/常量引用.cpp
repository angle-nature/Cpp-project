#include<iostream>
using namespace std;

void showValue(const int& val)
{
	//val = 20;  �β���const���κ󲻿��ٸ���
	cout << "val=" << val << endl;
}

int main()
{
	//int& ref = 10;  //���ñ�����Ҫһ���Ϸ����ڴ�ռ䣬������д���

	//����const�Ϳ�����
	const int& ref = 10;  //�������Զ��Ż����������Զ�ת��Ϊ��int temp=10;int &ref=temp;

	//����const���κ� ref��Ϊ�����޸ĵı���
	//ref = 20;  ����

	//�������������÷�ֹ������޸�ʵ��
	int a = 100;
	showValue(a);

	system("pause");
	return 0;
}