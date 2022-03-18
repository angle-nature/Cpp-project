#include<iostream>
using namespace std;

class Person
{
public:

	//静态成员函数
	//所有对象共享一个函数
    //静态成员函数只能访问静态成员变量
	static void func01()
	{
		m_A = 100;
		//m_B = 20;  静态成员函数只能访问静态成员变量
		cout << "static void func01 的调用" << endl;
	}

	//静态成员变量
	//所有对象共享一份数据
	//编译阶段就分配内存
	//类内声明，类外初始化
	static int m_A; 

	int m_B;
};

//静态变量类外赋初值
int Person::m_A = 10;

void test01()
{
	Person p1;
	
	cout << p1.m_A << endl;

	Person p2;
	p2.m_A = 200;

	cout << p1.m_A << endl;  //p1与p2共享一份数据  故输出200
}

//静态成员变量
void test02()
{
	//1、通过对象访问
	Person p;
	cout<<p.m_A<<endl;

	//2、通过类名访问
	cout << Person::m_A << endl;
}

//静态成员函数
void test03()
{
	//1、通过对象访问
	Person p;
	p.func01();

	//2、通过类名访问
	Person::func01();
}

int main()
{
	test01();
	test02();
	test03();

	system("pause");

	return 0;
}