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

//deque容器的插入和删除操作

//两端操作
void test()
{
	deque<int>d1;

	//尾插
    d1.push_back(10);
	d1.push_back(20);

	//头插
	d1.push_front(100);
	d1.push_front(200);

	cout << d1 << endl;

	//尾删
	d1.pop_back();  //删除最后一个元素
	cout << d1 << endl;

	//头删
	d1.pop_front();
	cout << d1 << endl;

	//插入 第一个参数是迭代器
	d1.insert(d1.begin() + 2, 100);
	cout << d1 << endl;

	d1.insert(d1.begin(), 2, 317);
	cout << d1 << endl;

	//按区间插入
	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);

	d1.insert(d1.begin(), d2.begin(), d2.end());
	cout << d1 << endl;

	//删除 参数也是迭代器
	d1.erase(d1.begin() + 3);
	cout << d1 << endl;

	//区间删除
	d1.erase(d1.begin() + 4, d1.end() - 1);
	cout << d1 << endl;

	//清空
	d1.clear();
	cout << d1 << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}