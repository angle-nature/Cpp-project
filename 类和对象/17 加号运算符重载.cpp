#include<iostream>
using namespace std;

//注意事项：对于内置的数据类型的表达式的运算符是不可能改变的

class Person
{
public:

	//成员函数重载+
	//加号运算符重载   operator+  作函数名  加减乘除的重载类似
	//Person operator+(Person& p)
	//{
	//	Person temp;

	//	temp.m_A = this->m_A + p.m_A;
	//	temp.m_B = this->m_B + p.m_B;

	//	return temp;
	//}

	int m_A;
	int m_B;
};

//全局函数重载+
Person operator+(Person &p1,Person &p2)
{
	Person temp;

	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;

	return temp;
}

Person operator+(Person& p1, int num)
{
	Person temp;

	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;

	return temp;
}

void test01()
{
	Person p1;

	p1.m_A = 10;
	p1.m_B = 20;

	Person p2;

	p2.m_A = 30;
	p2.m_B = 40;

	//成员函数重载+本质调用
	//Person p3=p1.operator+(p2);

	//全局函数重载+本质调用
	//Person p3=operator+(p1,p2);

	Person p3 = p1 + p2;  //加号运算符重载(简化版）

	//重载运算符也可以发生函数重载
	Person p4 = p1 + 10;  //Person operator+(Person& p1, int num)


	cout << p3.m_A << endl;
	cout << p3.m_B << endl;

	cout << p4.m_A << endl;
	cout << p4.m_B << endl;
}

int main()
{
	test01();

	system("pause");

	return 0;
}