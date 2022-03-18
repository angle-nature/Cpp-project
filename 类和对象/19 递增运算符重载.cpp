#include<iostream>
using namespace std;

class MyInteger
{
	//全局函数作友元
	friend ostream& operator<<(ostream& cout, MyInteger myint);

public:

	MyInteger()
	{
		m_Myint = 0;
	}

	//前置递增
	MyInteger& operator++() //必须要返回引用  否则无法进行连续多次递增
	{
		//先++
		this->m_Myint++;

		//再返回
		return *this;
	}

	//后置递增
	MyInteger operator++(int)
	{
		//记录当前本身的值，然后让本身的值加上1，但是返回的是以前的值，达到先返回再++的目的
		MyInteger temp = *this;

		this->m_Myint++;

		return temp;
	}

private:

	int m_Myint;

};

//只能用全局函数重载<<
ostream& operator<<(ostream& cout, MyInteger myint)  //cout属于 ostream类  且只有一个 必须要用 引用
{
	cout << "myint= " << myint.m_Myint;
	return cout;  //返回cout 是为了可以继续打印其他内容
}

void test01()
{
	MyInteger myint;

	cout << ++(++myint) << endl;
	cout << myint << endl;

}

void test02()
{
	MyInteger myint;

	cout << (myint++)++ << endl;
	cout << myint << endl;
}

int main()
{
	test01();
	test02();

	system("pause");

	return 0;
}