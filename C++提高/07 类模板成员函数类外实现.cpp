#include<iostream>
using namespace std;
#include"Person.h"

template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age);

	void showPerson();

	T1 m_Name;
	T2 m_Age;
};

//��ģ���Ա����������ʵ��
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	m_Name = name;
	m_Age = age;
}

template<class T1, class T2>
void Person<T1,T2>::showPerson()
{
	cout << "������" << m_Name << endl;
	cout << "���䣺" << m_Age << endl;
}

int main()
{
	Person<string, int>p("����", 18);
	p.showPerson();

	system("pause");

	return 0;
}