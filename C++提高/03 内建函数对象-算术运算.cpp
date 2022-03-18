#include<iostream>
using namespace std;
#include<functional>

//内建函数对象 算数仿函数

void test()
{
	negate<int> n; //一元仿函数 取反仿函数
	cout<<n(51)<<endl;

	plus<int> p;  //二元仿函数 加法
	cout << p(10, 29) << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}