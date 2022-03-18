#include<iostream>
using namespace std;

class Person
{
public:

	//构造函数初始化变量
	Person(int a,int b):m_A(a),m_B(b)
	{
		
	}

	//第二种初始化方式
	//Person() :m_A(20), m_B(30)
	//{

	//}

	int m_A;
	int m_B;
};

void test01()
{
	Person p(10,20); 
	cout << p.m_A <<endl<< p.m_B << endl;
}



int main()
{
	test01();

	system("pause");

	return 0;
}