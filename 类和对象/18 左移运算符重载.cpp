#include<iostream>
using namespace std;

class Person
{
public:

	//利用成员函数重载 左移运算符 p.operator(cout) 简化版本： p<<cout
	//所以一般不利用成员函数重载<<运算符  无法将 cout 放在 << 左侧

	int m_A;
	int m_B;
};

//只能用全局函数重载<<
ostream& operator<<(ostream& cout, Person p)  //cout属于 ostream类  且只有一个 必须要用 引用
{
	cout << "p.m_A= " << p.m_A << " p.m_B= " << p.m_B;
	return cout;  //返回cout 是为了可以继续打印其他内容
}

void test01()
{
	Person p;

	p.m_A = 10;
	p.m_B = 20;

	cout << p << endl;
}

int main()
{
	test01();

	system("pause");

	return 0;
}