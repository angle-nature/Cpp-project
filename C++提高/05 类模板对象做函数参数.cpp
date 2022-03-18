#include<iostream>
using namespace std;

//类模板对象做函数参数

template<class T1,class T2>
class Person
{
public:
	Person(T1 name, T2 age)
	{
		m_Name = name;
		m_Age = age;
	}

	void showPerson()
	{
		cout << "姓名：" << m_Name << endl;
		cout << "年龄：" << m_Age << endl;
	}

	T1 m_Name;
	T2 m_Age;
};

//1、指定传入类型
void printPerson01(Person<string,int>&p)
{
	p.showPerson();
}

void test01()
{
	Person<string, int>p("张三", 18);
	printPerson01(p);
}

//2、参数模板化
template<class T1,class T2>
void printPerson02(Person<T1, T2>&p)
{
	p.showPerson();
	cout << "T1的类型为：" << typeid(T1).name() << endl;
	cout << "T2的类型为：" << typeid(T2).name() << endl;
}

void test02()
{
	Person<string, int>p("李四", 18);
	printPerson02(p);
}

//3、整个类模板化
template<class T>
void printPerson03(T & p)
{
	p.showPerson();
}

void test03()
{
	Person<string, int>p("王五", 18);
	printPerson03(p);
}

int main()
{
	//test01();
	//test02();
	test03();

	system("pause");

	return 0;
}