#include<iostream>
using namespace std;

class Base1
{
public:

	Base1()
	{
		m_A = 100;
	}

	int m_A;
};

class Base2
{
public:

	Base2()
	{
		m_A = 200;
	}

	int m_A;
};

//��̳��﷨
//�﷨�� class ���ࣺ�̳з�ʽ ����1���̳з�ʽ����2�� ......
class Son :public Base1, public Base2
{
public:
	
	Son()
	{
		m_B = 300;
	}

	int m_B;
};

void test()
{
	Son s;

	//���ʸ����е�ͬ����Ա �����������
	cout << "Base1::m_A=" << s.Base1::m_A << endl;
	cout << "Base2::m_A=" << s.Base2::m_A << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}