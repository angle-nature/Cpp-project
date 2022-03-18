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

//vector容器的容量和大小操作
void test()
{
	vector<int>v1; 

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout << v1 << endl;

	if (v1.empty())
	{
		cout << "v1为空" << endl;
	}
	else
	{
		cout << "v1不为空" << endl;
		cout << "v1的容量为：" << v1.capacity() << endl;
		cout << "v1的大小为：" << v1.size() << endl;
	}

	//重新指定大小
	v1.resize(15);
	//v1.resize(15,100); //也可以利用resize重载版本，指定填充值参数2（100）
	cout << v1 << endl; //如果重新指定的比原来的长了，默认用0填充新的位置

	v1.resize(5);
	cout << v1 << endl; //如果重新指定的比原来的短了，超出部分自动删除
}

int main()
{
	test();

	system("pause");

	return 0;
}