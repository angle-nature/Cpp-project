#include<iostream>
using namespace std;

int main()
{
	int a = 10;

	//引用的本质是指针常量  相当于 int* const ref=&a;
	//指针常量所指地址不能更改  只能改变地址所对应的值  所以引用一旦初始化后就不能更改
	int& ref = a;
	ref = 20;  //内部发现ref是引用 自动转换为 *ref=20;

	system("pause");
	return 0;
}