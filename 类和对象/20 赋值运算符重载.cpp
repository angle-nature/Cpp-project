#include<iostream>
using namespace std;

class Person
{
	friend void test();

public:

	Person(int age)
	{
		m_Age = new int(age);
	}

	//重载赋值运算符
	Person& operator=(Person &p)
	{

		this->m_Age = new int(*p.m_Age);

		return *this;
	}

	//利用析构函数释放在堆区开辟的内存
	~Person()
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}

private:

	int* m_Age;
};

void test()
{
	Person p1(18);
	Person p2(19);
	Person p3(20);

	p3 = p2 = p1;

	cout << "p1的年龄为：" << *p1.m_Age << endl;
	cout << "p2的年龄为：" << *p2.m_Age << endl;
	cout << "p3的年龄为：" << *p3.m_Age << endl;

}

int main()
{
	test();

	system("pause");

	return 0;
}