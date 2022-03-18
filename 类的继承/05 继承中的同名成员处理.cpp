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
		cout << "Base 类的成员函数" << endl;
	}

	void func(int a)
	{
		cout << "Base - func(int a)调用" << endl;
	}

	void func1()
	{
		cout << "Base - func1调用" << endl;
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
		cout << "Son 类的成员函数" << endl;
	}

	int m_A;

};

//同名成员属性处理方式
void test01()
{
	Son s;

	cout << "Son 下的 m_A=" << s.m_A << endl;

	//如果通过子类对象 访问到父类中的同名成员属性，需加上作用域
	cout << "Base 下的 m_A=" << s.Base::m_A << endl;
}

//同名成员函数处理方式
void test02()
{
	Son s;
	s.func();

	//如果通过子类对象 访问到父类中的同名成员函数，也需加上作用域
	s.Base::func();

	//如果子类中出先父类的同名成员函数 子类的同名成员函数会隐藏父类中所有的同名成员函数
	//如果想访问 必须加上作用域
	s.Base::func(100);

	//如果子类中没有与父类的同名成员函数  访问父类中的成员函数 则无需加作用域
	s.func1();
}

int main()
{
	test01();
	test02();

	system("pause");

	return EXIT_SUCCESS;
}