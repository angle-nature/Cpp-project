#include<iostream>
using namespace std;
#include<vector>
#include<functional>
#include<algorithm>

//内建函数对象 算数仿函数

void test()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(30);
	v.push_back(20);
	v.push_back(50);

	sort(v.begin(), v.end()); //默认升序

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//STL内建仿函数 大于仿函数 greater<T>()
	sort(v.begin(), v.end(), greater<int>());  //降序

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
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