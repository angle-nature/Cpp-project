#include<iostream>
using namespace std;
#include<vector>

//vector��������Զ�����������
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

void test01()
{
	vector<Person> v;
	
	Person p1("aaa", 18);
	Person p2("bbb", 19);
	Person p3("ccc", 20);
	Person p4("ddd", 21);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	for (vector<Person>::iterator it = v.begin(); it!= v.end(); it++)
	{
		cout << "������" << (*it).m_Name << "���䣺" << it->m_Age << endl;
	}
}

//����Զ�������ָ��
void test02()
{
	vector<Person*> v;

	Person p1("aaa", 18);
	Person p2("bbb", 19);
	Person p3("ccc", 20);
	Person p4("ddd", 21);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);

	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "������" << (**it).m_Name << "���䣺" << (*it)->m_Age << endl;
	}
}

int main()
{
	//test01();
	test02();

	system("pause");

	return 0;
}