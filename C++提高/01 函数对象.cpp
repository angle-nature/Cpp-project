#include<iostream>
using namespace std;

//1、函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

void test01()
{
	MyAdd myAdd;
	cout<<myAdd(10, 10)<<endl;
}

//2、函数对象可以有自己的状态
class MyPrint
{
public:

	MyPrint()
	{
		count = 0;
	}

	void operator()(string txt)
	{
		cout << txt << endl;
		this->count++;  //统计使用次数
	}

	int count;  //内部自己状态
};

void test02()
{
	MyPrint myPrint;
	myPrint("hello world");
	myPrint("hello world");
	myPrint("hello world");
	cout << "myPrint调用次数：" << myPrint.count << endl;
}

//3、函数对象可以作为参数传递
void doPrint(MyPrint& mp, string txt)
{
	mp(txt);
}

void test03()
{
	MyPrint myPrint;
	doPrint(myPrint, "hello world");
}

int main()
{
	//test01();
	test02();
	//test03();

	system("pause");

	return 0;
}