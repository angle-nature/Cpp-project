#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		m_A = 100;
	}

	void func()
	{
		cout << "Base ��ĳ�Ա����" << endl;
	}

	void func(int a)
	{
		cout << "Base - func(int a)����" << endl;
	}

	void func1()
	{
		cout << "Base - func1����" << endl;
	}

	int m_A;
};


class Son :public Base
{
public:
	Son()
	{
		m_A = 200;
	}

	void func()
	{
		cout << "Son ��ĳ�Ա����" << endl;
	}

	int m_A;

};

//ͬ����Ա���Դ���ʽ
void test01()
{
	Son s;

	cout << "Son �µ� m_A=" << s.m_A << endl;

	//���ͨ��������� ���ʵ������е�ͬ����Ա���ԣ������������
	cout << "Base �µ� m_A=" << s.Base::m_A << endl;
}

//ͬ����Ա��������ʽ
void test02()
{
	Son s;
	s.func();

	//���ͨ��������� ���ʵ������е�ͬ����Ա������Ҳ�����������
	s.Base::func();

	//��������г��ȸ����ͬ����Ա���� �����ͬ����Ա���������ظ��������е�ͬ����Ա����
	//�������� �������������
	s.Base::func(100);

	//���������û���븸���ͬ����Ա����  ���ʸ����еĳ�Ա���� �������������
	s.func1();
}

int main()
{
	test01();
	test02();

	system("pause");

	return EXIT_SUCCESS;
}