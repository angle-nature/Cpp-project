#include<iostream>
using namespace std;
#include<deque>

//deque容器的数据存取操作
void test()
{
	deque<int>d1;

	//尾插
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}

	//利用[]的方式访问单个元素
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1[i] << " ";
	}
	cout << endl;

	//利用at方式访问单个元素
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1.at(i) << " ";
	}
	cout << endl;

	//获取第2个元素
	cout << "第一个元素：" << d1.front() + 1 << endl;

	//获取最后一个元素
	cout << "最后一个元素：" << d1.back() << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}