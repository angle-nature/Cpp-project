#include<iostream>
using namespace std;

//模板局限性
//模板并不是万能的	有些特定的数据类型 需要用具体化方式做具体实现

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

//对比两个函数是否相等
template<class T>
bool myCompare(T a, T b)
{
	return a == b;
}

//利用具体化Person的版本实现代码，具体化优先调用
template<> bool myCompare(Person p1, Person p2)
{
	return (p1.m_age == p2.m_age && p1.m_name == p2.m_name);
}

int main()
{
	Person p1(18, "张三");
	Person p2(18, "张三");

	if (myCompare(p1, p2))
		cout << "p1==p2" << endl;
	else
		cout << "p1!=p2" << endl;


	system("pause");

	return 0;
}