#include<iostream>
using namespace std;

//通过全局函数，打印Person信息

template<class T1, class T2>
class Person;

//类外实现
template<class T1, class T2>
void printPerson(Person <T1, T2>p)
{
	cout << "姓名：" << p.m_Name << endl;
	cout << "年龄：" << p.m_Age << endl;
}

template<class T1, class T2>
class Person
{
	//全局函数，类内实现
	//friend void printPerson(Person <T1, T2>p)
	//{
	//	cout << "姓名：" << p.m_Name << endl;
	//	cout << "年龄：" << p.m_Age << endl;
	//}

	//全局函数，类外实现
	//加空模板参数列表
	//如果全局函数是类外实现，需要提前让编译器知道这个函数的存在
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
	Person<string, int>p("张三", 18);
	printPerson(p);

	system("pause");

	return 0;
}