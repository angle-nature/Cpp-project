#include<iostream>
using namespace std;

class Base
{
public:

	//纯虚函数声明格式： virtual 返回值类型 函数名（）=0；
	//类中只要有一个纯虚函数，这个类称为抽象类
	//抽象类特点：
	//1、无法实例化对象
	//2、抽象类的子类 必须要重写父类中的纯虚函数 否则也属于抽象类
	virtual void func() = 0;
};

class Son :public Base
{
public:

    void func()
	{
		cout << "func 函数的调用" << endl;
	}
};

void test()
{
	//Base b;    //抽象类无法实例化
	//new Base;  //抽象类无法实例化

	//Son s;  //子类必须重写父类中的实例化否则无法实例化

	Base* base = new Son;
	base->func();
}

int main()
{
	test();

	system("pause");

	return 0;
}