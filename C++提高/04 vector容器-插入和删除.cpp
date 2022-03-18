#include<iostream>
using namespace std;
#include<vector>

ostream& operator<<(ostream& cout, vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
	{
		cout << *it << " ";
	}
	return cout;
}

//vector容器的插入和删除操作
void test()
{
	vector<int>v1;

	//尾插
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout << v1 << endl;

	//尾删
	v1.pop_back();  //删除最后一个元素
	cout << v1 << endl;

	//插入 第一个参数是迭代器
	v1.insert(v1.begin()+2, 100);
	cout << v1 << endl;

	v1.insert(v1.begin(), 2, 317);
	cout << v1 << endl;

	//删除 参数也是迭代器
	v1.erase(v1.begin()+3);
	cout << v1 << endl;

	//区间删除
	v1.erase(v1.begin()+4, v1.end()-1);
	cout << v1 << endl;

	//清空
	v1.clear();
	cout << v1 << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}