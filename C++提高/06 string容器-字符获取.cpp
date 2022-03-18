#include<iostream>
using namespace std;

//string 字符获取

void test()
{
	string str1 = "hello";

	//1、通过[]访问单个字符
	for (int i = 0; i < str1.size(); i++)
	{
		cout << str1[i] << " ";
	}
	cout << endl;

	//通过at方式访问单个字符
	for (int i = 0; i < str1.size(); i++)
	{
		cout << str1.at(i) << " ";
	}
	cout << endl;

	//修改单个字符
	str1[0] = 'x';
	cout << "str1=" << str1 << endl;

	str1.at(1) = 'd';
	cout << "str1=" << str1 << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}