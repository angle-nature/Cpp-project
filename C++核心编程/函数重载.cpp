#include<iostream>
using namespace std;

//函数重载的条件：
//1、作用域相同
//2、函数名相同，返回值类型相同
//3、函数参数的个数、类型、顺序不同
void func()
{
	cout << "' func()调用" << endl;
}

void func(int a)
{
	cout << "func(int a)调用" << endl;
}

void func(int a,int b)
{
	cout << " func(int a,int b)调用" << endl;
}

void func(int a,float b)
{
	cout << "func(int a,float b)调用" << endl;
}

void func(float a,int b)
{
	cout << " func(float a,int b)调用" << endl;
}

int main()
{


	system("pause");

	return 0;
}