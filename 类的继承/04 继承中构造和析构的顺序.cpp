#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base�Ĺ��캯��" << endl;
	}

	~Base()
	{
		cout << "Base����������" << endl;
	}
};


class Son :public Base
{
public:
	Son()
	{
		cout << "Son�Ĺ��캯��" << endl;
	}

	~Son()
	{
		cout << "Son����������" << endl;
	}
	
};

//�ȵ��ø���Ĺ��캯�� �ٵ��������еĹ��캯�� �����빹��˳���෴
void test()
{
	Son s;
	
}

int main()
{
	test();

	system("pause");

	return 0;
}