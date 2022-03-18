#include"Person.h"

//类模板成员函数的类外实现
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	m_Name = name;
	m_Age = age;
}

template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << "姓名：" << m_Name << endl;
	cout << "年龄：" << m_Age << endl;
}