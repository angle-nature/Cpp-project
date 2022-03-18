#include<iostream>
using namespace std;

//深拷贝与浅拷贝
class Person
{
public:

	Person()
	{
		cout << "Person的无参构造函数调用" << endl;
	}

	Person(int a,int height)
	{
		m_age = a;
		m_Height = new int(height);    //利用new创建的数据，会返回该数据对应的类型的指针 放在堆区

		cout << "Person的有参构造函数调用" << endl;
	}

	Person(const Person& p)
	{
		m_age = p.m_age;
		//m_Height=p.m_Height;   这是默认拷贝函数写的实现  浅拷贝
		m_Height = new int(*p.m_Height);  //在堆区开辟一块新的地址来接受传进来的值  深拷贝

		cout << "Person的拷贝构造函数调用" << endl;
	}

	//析构函数
	~Person()
	{
		//利用析构函数释放堆区占用的内存
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;
		}
		cout << "Person的析构函数调用" << endl;
	}


	int m_age = 0;
	int* m_Height;
};

void test01()
{
	Person p1(20,180);  //有参构造

	cout << "P1的年龄为：" << p1.m_age << "身高为：" << *p1.m_Height << endl;

	Person p2(p1);  //拷贝构造

	cout << "P2的年龄为：" << p2.m_age << "身高为：" << *p2.m_Height << endl;

	//p1.m_Height 和 p2.m_Height 的地址不同 在析构函数调用时不会发生重复释放一个地址的错误
}


int main()
{
	test01();

	system("pause");

	return 0;
}