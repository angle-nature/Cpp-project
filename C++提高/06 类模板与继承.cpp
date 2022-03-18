#include<iostream>
using namespace std;

//类模板与继承

template<class T>
class Base
{
public:
	T m;
};

//class Son1:public Base //错误，必须要知道父类中的T类型，才能继承给子类
class Son1 :public Base<int>
{

};

//如果想灵活指定父类中的T类型，子类也需变成模板
template<class T1,class T2>
class Son2 :public Base<T2>
{
public:

	Son2()
	{
		cout << "T1的类型为：" << typeid(T1).name() << endl;
		cout << "T2的类型为：" << typeid(T2).name() << endl;
	}

	T1 m_A;
};

void test()
{
	Son2<int,char>s;
}

int main()
{
	test();

	system("pause");
	return 0;
}