#include<iostream>
using namespace std;

//拷贝构造函数的调用时机
class Person
{
public:
	//构造函数
	Person()
	{
		cout << "Person的无参构造函数调用" << endl;
	}

	Person(int a)
	{
		m_age = a;
		cout << "Person的有参构造函数调用" << endl;
	}

	//拷贝构造函数
	Person(const Person& p)
	{
		m_age = p.m_age;
		cout << "Person的拷贝构造函数调用" << endl;
	}

	//析构函数
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}


	int m_age = 0;
};

//1、使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
	Person p1(10);  //有参构造
	Person p2(p1);  //拷贝构造

	cout << "P2的年龄为：" << p2.m_age << endl;
}

//2、值传递的方式给函数参数传值  值传递
void doWork(Person p)
{

}

void test02()
{
	Person p;  //默认构造（无参构造）
	doWork(p); //拷贝构造
}

//3、值方式返回局部对象  值传递
Person doWork02()
{
	Person p;
	cout << (int*)&p << endl;
	return p;
}

void test03()
{
	Person p=doWork02();
	cout << (int*)&p << endl;
}

int main()
{
	//test01();
	//test02();
	test03();

	system("pause");

	return 0;
}