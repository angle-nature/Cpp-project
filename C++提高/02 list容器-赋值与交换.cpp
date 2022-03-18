#include<iostream>
using namespace std;
#include<list>

ostream& operator<<(ostream& cout, list<int>& L)
{
	for (list<int>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	return cout;
}

//list赋值
void test()
{
	list<int>L1; //默认构造 无参构造

	for (int i = 0; i < 10; i++)
	{
		L1.push_back(i);
	}
	cout << L1 << endl;

	//operator= 赋值
	list<int> L2 = L1;
	cout << L2 << endl;

	//assign
	list<int> L3;
	L3.assign(L1.begin(), L1.end()); //list的迭代器只能进行 ++ 或 --的操作
	cout << L3 << endl;

	//n个elem方式赋值
	list<int> L4;
	L4.assign(10, 100);
	cout << L4 << endl;

	//交换容器
	L1.swap(L4);
	cout << "交换后：" << endl;
	cout << "L1=" << L1 << endl;
	cout << "L4=" << L4 << endl;
}



int main()
{
	test();

	system("pause");

	return 0;
}