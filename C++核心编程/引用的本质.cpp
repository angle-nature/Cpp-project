#include<iostream>
using namespace std;

int main()
{
	int a = 10;

	//���õı�����ָ�볣��  �൱�� int* const ref=&a;
	//ָ�볣����ָ��ַ���ܸ���  ֻ�ܸı��ַ����Ӧ��ֵ  ��������һ����ʼ����Ͳ��ܸ���
	int& ref = a;
	ref = 20;  //�ڲ�����ref������ �Զ�ת��Ϊ *ref=20;

	system("pause");
	return 0;
}