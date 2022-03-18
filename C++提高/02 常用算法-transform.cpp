#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int func(int val)
{
	return val + 10;
}

void print01(int val)
{
	cout << val << " ";
}

void test()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), print01);
	cout << endl;

	vector<int> v1;
	v1.resize(v.size()); //先开辟空间  不先指定空间大小  无法搬运进去

	//利用逻辑非,将容器 v 搬运到容器 v1 中,并执行 +10 的操作
	transform(v.begin(), v.end(), v1.begin(), func);

	for_each(v1.begin(), v1.end(), print01);
	cout << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}