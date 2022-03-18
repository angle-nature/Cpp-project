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

//多继承语法
//语法： class 子类：继承方式 父类1，继承方式父类2， ......
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

	//访问父类中的同名成员 需加上作用域
	cout << "Base1::m_A=" << s.Base1::m_A << endl;
	cout << "Base2::m_A=" << s.Base2::m_A << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}