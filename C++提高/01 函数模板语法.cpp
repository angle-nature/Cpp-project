#include<iostream>
using namespace std;

//函数模板
template<typename T> //声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T是一个通用数据类型
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 10;
	int b = 20;

	//利用函数模板来交换
	//1、自动类型推导
	//mySwap(a, b);

	//2、显示指定类型
	mySwap<int>(a, b);

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	system("pause");

	return 0;
}