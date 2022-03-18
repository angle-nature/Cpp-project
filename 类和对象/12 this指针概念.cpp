#include<iostream>
using namespace std;

class Person
{
public:

	Person(int age)
	{
		//this指针指向被调用的成员函数所属的对象
		this->age = age;
	}

	Person& PersonAddAge(Person p)  //此处一定要返回对象的引用  否则会将返回的值赋予一个新的对象  而不是p2本身
	{
		this->age += p.age;

		//this指向p2的指针，*this则指向p2这个对象本体
		return *this;
	}

	int age;
};

//1、解决名称冲突
void test01()
{
	Person p(20);
	cout << "p的年龄为：" << p.age << endl;
}

//2、返回对象本身用*this
void test02()
{
	Person p1(10);
	Person p2(10);

	//链式编程思想
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);  // 等价于 p2.age=p2.age+p1.age+p1.age+p1.age;

	cout << "p2的年龄为：" << p2.age << endl;
}

int main()
{
	//test01();
	test02();

	system("pause");

	return 0;
}