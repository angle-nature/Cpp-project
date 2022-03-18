#include<iostream>
using namespace std;

//构造函数的分类及调用
//分类
//按参数分类 无参构造（默认构造）和 有参构造
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


	int m_age=0;
};

//调用
void test()
{
	//1、括号法
	Person p1;      //默认构造函数的调用
	Person p2(10);  //有参构造函数的调用
	Person p3(p1);  //拷贝构造函数的调用

	//注意事项：调用默认构造函数时，不能加括号 如p1()，编译器会认为这是函数声明
	//例：  Person p()；  

	//2、显示法
	Person p01;
	Person p02 = Person(10);  //有参构造函数
	Person p03 = Person(p01); //拷贝构造函数

	//Person(10); //匿名对象 特点：当前执行结束后，系统会立即回收掉匿名对象

	//注意事项：
	//不要利用拷贝构造函数初始化匿名对象 编译器会认为 Person（p03）===Person p3；
	//Person(p03);

	//3、隐式转换法
	Person p4 = 10; //相当于写了 Person p4=Person(10);
	Person p5 = p4; //相当于写了 Person p5=Person(p4);
}

int main()
{
	test();

	system("pause");

	return 0;
}