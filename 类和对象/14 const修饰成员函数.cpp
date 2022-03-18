#include<iostream>
using namespace std;

class Person
{
public:

	//this指针的本质 是 指针常量 因为this 是指向调用成员函数的对象的 指向不可修改  等价于  Person * const this
	//成员函数后面加上 const 修饰的是this指针  等价于  const Person * const this  指向及指向的值都不可改变
	void showPerson() const    //常函数
	{
		//this->m_A = 100;
		this->m_B = 200;
	}

	int m_A;
	mutable int m_B; //特殊变量 即使在常函数中 也可以修改这个值 加上关键字mutable
	
};

void test01()
{
	Person p;
	p.showPerson();
}

void test02()
{
	const Person p;  //在对象前加const，变成常对象
	//p.m_A = 100;  不可修改
	p.m_B = 200;    //特殊变量 可修改

	//常对象只能调用常函数 因为常函数可能会修改普通变量的值 而常对象是不能修改普通成员变量的值的
	p.showPerson();
}

int main()
{
	test01();
	test02();

	system("pause");

	return 0;
}