#include<iostream>
using namespace std;
#include<deque>

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it < d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//vector容器的容量和大小操作
void test()
{
	deque<int>d1;

	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	if (d1.empty())
	{
		cout << "d1为空" << endl;
	}
	else
	{
		cout << "d1不为空" << endl;
		cout << "d1的大小为：" << d1.size() << endl;
		//deque容器没有容量的概念
	}

	//重新指定大小
	d1.resize(15);
	//d1.resize(15,100); //也可以利用resize重载版本，指定填充值参数2（100）
	printDeque(d1); //如果重新指定的比原来的长了，默认用0填充新的位置

	d1.resize(5);
	printDeque(d1); //如果重新指定的比原来的短了，超出部分自动删除
}

int main()
{
	test();

	system("pause");

	return 0;
}