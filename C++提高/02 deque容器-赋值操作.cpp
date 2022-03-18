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

//deque��ֵ
void test()
{
	deque<int>d1; //Ĭ�Ϲ��� �޲ι���

	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	cout << d1 << endl;

	//operator= ��ֵ
	deque<int> d2 = d1;
	cout << d2 << endl;

	//assign
	deque<int> d3;
	d3.assign(d1.begin(), d1.end()); //ǰ�պ�
	cout << d3 << endl;

	//n��elem��ʽ��ֵ
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