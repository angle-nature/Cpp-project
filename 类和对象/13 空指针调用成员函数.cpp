#include<iostream>
using namespace std;

class Person
{
public:

	void showClassName()
	{
		cout << "this is Person class" << endl;
	}

	void showPersonAge()
	{
		if (this == NULL)
		{
			return;
		}
		//�����ָ��Ϊ��ָ��
		cout << "age= " << this->m_age << endl;
	}

	int m_age;
};

void test01()
{
	Person* p=NULL;

	p->showClassName();
	p->showPersonAge();
}

int main()
{
	test01();

	system("pause");

	return 0;
}