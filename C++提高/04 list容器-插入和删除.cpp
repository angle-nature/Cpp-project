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

//vector容器的插入和删除操作
void test()
{
	list<int>L1;

	//尾插
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);

	//头插
	L1.push_front(100);
	L1.push_front(200);
	L1.push_front(300);

	cout << L1 << endl;

	//尾删
	L1.pop_back();  //删除最后一个元素
	cout << L1 << endl;

	//头删
	L1.pop_front();
	cout << L1 << endl;

	//插入 第一个参数是迭代器
	L1.insert(L1.begin(), 100);
	cout << L1 << endl;

	L1.insert(L1.begin(), 2, 317);
	cout << L1 << endl;

	//删除 参数也是迭代器
	L1.erase(L1.begin());
	cout << L1 << endl;

	L1.push_back(10000);
	L1.push_back(10000);
	L1.push_back(10000);
	cout << L1 << endl;

	L1.remove(10000); //移除所有数据为10000的元素
	cout << L1 << endl;

	//区间删除
	L1.erase(L1.begin(), L1.end());
	cout << L1 << endl;

	//清空
	L1.clear();
	cout << L1 << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}