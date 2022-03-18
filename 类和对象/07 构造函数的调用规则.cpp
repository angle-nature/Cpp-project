#include<iostream>
using namespace std;

//构造函数的调用规则
//1、创建一个类，C++编译器会给每个类都添加至少三个函数
//默认构造函数（空实现）
//有参构造函数（空实现）
//拷贝构造函数（值拷贝）

//2、
//如果写了有参构造函数，编译器则不会提供默认构造函数，但依然会提供拷贝构造函数
//如果写了拷贝构造函数，编译器则不会提供其他普通构造函数了
class Person
{
public:
	//构造函数
	Person()
	{
		cout << "Person的无参构造函数调用" << endl;
	}

	Person(int a)
	{
		m_age = a;
		cout << "Person的有参构造函数调用" << endl;
	}

	//拷贝构造函数
	Person(const Person& p)
	{
		m_age = p.m_age;
		cout << "Person的拷贝构造函数调用" << endl;
	}

	//析构函数
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}


	int m_age = 0;
};

void test01()
{
	Person p1(10);  //有参构造
	Person p2(p1);  //拷贝构造

	cout << "P2的年龄为：" << p2.m_age << endl;
}


void test02()
{
	Person p;  //默认构造（无参构造）
}


int main()
{
	//test01();
	//test02();

	system("pause");

	return 0;
}