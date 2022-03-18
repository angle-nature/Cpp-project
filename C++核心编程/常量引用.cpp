#include<iostream>
using namespace std;

void showValue(const int& val)
{
	//val = 20;  形参用const修饰后不可再更改
	cout << "val=" << val << endl;
}

int main()
{
	//int& ref = 10;  //引用本身需要一个合法的内存空间，因此这行错误

	//加入const就可以了
	const int& ref = 10;  //编译器自动优化，将代码自动转换为：int temp=10;int &ref=temp;

	//但用const修饰后 ref成为不可修改的变量
	//ref = 20;  错误

	//函数常利用引用防止误操作修改实参
	int a = 100;
	showValue(a);

	system("pause");
	return 0;
}