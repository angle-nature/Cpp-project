#include<iostream>
using namespace std;

//ͨ��ȫ�ֺ�������ӡPerson��Ϣ

template<class T1, class T2>
class Person;

//����ʵ��
template<class T1, class T2>
void printPerson(Person <T1, T2>p)
{
	cout << "������" << p.m_Name << endl;
	cout << "���䣺" << p.m_Age << endl;
}

template<class T1, class T2>
class Person
{
	//ȫ�ֺ���������ʵ��
	//friend void printPerson(Person <T1, T2>p)
	//{
	//	cout << "������" << p.m_Name << endl;
	//	cout << "���䣺" << p.m_Age << endl;
	//}

	//ȫ�ֺ���������ʵ��
	//�ӿ�ģ������б�
	//���ȫ�ֺ���������ʵ�֣���Ҫ��ǰ�ñ�����֪����������Ĵ���
	friend void printPerson<>(Person <T1, T2>p);


public:
	Person(T1 name, T2 age)
	{
		m_Name = name;
		m_Age = age;
	}

private:

	T1 m_Name;
	T2 m_Age;
};

int main()
{
	Person<string, int>p("����", 18);
	printPerson(p);

	system("pause");

	return 0;
}