#include<iostream>
using namespace std;
#include<deque>

ostream& operator<<(ostream& cout, deque<int>& d)
{
	for (deque<int>::iterator it = d.begin(); it < d.end(); it++)
	{
		cout << *it << " ";
	}
	return cout;
}

//deque赋值
void test()
{
	deque<int>d1; //默认构造 无参构造

	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	cout << d1 << endl;

	//operator= 赋值
	deque<int> d2 = d1;
	cout << d2 << endl;

	//assign
	deque<int> d3;
	d3.assign(d1.begin(), d1.end()); //前闭后开
	cout << d3 << endl;

	//n个elem方式赋值
	deque<int> d4;
	d4.assign(10, 100);
	cout << d4 << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}