#include<iostream>
using namespace std;

//ģ�������
//ģ�岢�������ܵ�	��Щ�ض����������� ��Ҫ�þ��廯��ʽ������ʵ��

class Person
{
public:
	Person(int age, string name)
	{
		m_age = age;
		m_name = name;
	}

	int m_age;
	string m_name;
};

//�Ա����������Ƿ����
template<class T>
bool myCompare(T a, T b)
{
	return a == b;
}

//���þ��廯Person�İ汾ʵ�ִ��룬���廯���ȵ���
template<> bool myCompare(Person p1, Person p2)
{
	return (p1.m_age == p2.m_age && p1.m_name == p2.m_name);
}

int main()
{
	Person p1(18, "����");
	Person p2(18, "����");

	if (myCompare(p1, p2))
		cout << "p1==p2" << endl;
	else
		cout << "p1!=p2" << endl;


	system("pause");

	return 0;
}