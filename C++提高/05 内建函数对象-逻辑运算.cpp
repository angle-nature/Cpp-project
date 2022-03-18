#include<iostream>
using namespace std;
#include<vector>
#include<functional>
#include<algorithm>

//逻辑非 logical_not

void test()
{
	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	vector<bool> v1;
	v1.resize(v.size()); //先开辟空间  不先指定空间大小  无法搬运进去

	//利用逻辑非,将容器 v 搬运到容器 v1 中,并执行逻辑取反操作
	transform(v.begin(), v.end(), v1.begin(), logical_not<bool>()); 

	for (vector<bool>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}