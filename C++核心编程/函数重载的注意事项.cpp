#include<iostream>
using namespace std;

//当函数重载碰到引用参数
void func01(int& a)
{
	cout << "func01(int& a)的调用" << endl;
}

void func01(const int& a)
{
	cout << "func01(const int& a)的调用" << endl;
}

//当函数重载遇到默认参数
void func02(int a, int b = 10)
{
	cout << "func02(int a, int b = 10)的调用" << endl;
}

void func02(int a)
{
	cout << "func02(int a)" << endl;
}

int main()
{
	int a = 10;
	func01(a);    //调用 func01(int& a)

	func01(10);   //调用 func01(const int& a)

	//func02(a);    //碰到默认参数产生歧义  报错  应尽量避免

	system("pause");
	return 0;
}