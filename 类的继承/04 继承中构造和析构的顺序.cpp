#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base的构造函数" << endl;
	}

	~Base()
	{
		cout << "Base的析构函数" << endl;
	}
};


class Son :public Base
{
public:
	Son()
	{
		cout << "Son的构造函数" << endl;
	}

	~Son()
	{
		cout << "Son的析构函数" << endl;
	}
	
};

//先调用父类的构造函数 再调用子类中的构造函数 析构与构造顺序相反
void test()
{
	Son s;
	
}

int main()
{
	test();

	system("pause");

	return 0;
}