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

	//���ظ�ֵ�����
	Person& operator=(Person &p)
	{

		this->m_Age = new int(*p.m_Age);

		return *this;
	}

	//�������������ͷ��ڶ������ٵ��ڴ�
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

	cout << "p1������Ϊ��" << *p1.m_Age << endl;
	cout << "p2������Ϊ��" << *p2.m_Age << endl;
	cout << "p3������Ϊ��" << *p3.m_Age << endl;

}

int main()
{
	test();

	system("pause");

	return 0;
}