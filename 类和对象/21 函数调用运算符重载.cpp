#include<iostream>
using namespace std;

class MyPrint
{
public:

	//重载（）运算符  也称仿函数
	void operator()(string text)
	{
		cout << text << endl;
	}
};

void test()
{
	MyPrint myprint;
	myprint.operator()("呜啦啦啦啦");

	//MyPrint() 称为匿名对象  使用之后立即被释放
	MyPrint()("噜啦啦噜啦啦");
}

int main()
{
	test();

	system("pause");

	return 0;
}