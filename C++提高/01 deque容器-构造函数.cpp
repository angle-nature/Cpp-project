#include<iostream>
using namespace std;
#include<deque>

//deque¹¹Ôìº¯Êý

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it < d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test()
{
	deque<int> d;

	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);
	}
	printDeque(d);

	deque<int>d1(d.begin(), d.end());
	printDeque(d1);

	deque<int>d2(10, 100);
	printDeque(d2);

	deque<int>d3(d2);
	printDeque(d3);
}

int main()
{
	test();

	system("pause");

	return 0;
}