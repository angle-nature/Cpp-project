#include<iostream>
using namespace std;

class Base
{
public:

	//���麯��������ʽ�� virtual ����ֵ���� ����������=0��
	//����ֻҪ��һ�����麯����������Ϊ������
	//�������ص㣺
	//1���޷�ʵ��������
	//2������������� ����Ҫ��д�����еĴ��麯�� ����Ҳ���ڳ�����
	virtual void func() = 0;
};

class Son :public Base
{
public:

    void func()
	{
		cout << "func �����ĵ���" << endl;
	}
};

void test()
{
	//Base b;    //�������޷�ʵ����
	//new Base;  //�������޷�ʵ����

	//Son s;  //���������д�����е�ʵ���������޷�ʵ����

	Base* base = new Son;
	base->func();
}

int main()
{
	test();

	system("pause");

	return 0;
}